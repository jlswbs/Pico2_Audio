// Stereo delay neuron resonator //

#include "hardware/structs/rosc.h"
#include <I2S.h>

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define I2S_WORDS     64

#define SAMPLE_RATE 44100
#define BPM         30
#define N_NEURONS   8
#define MAX_DELAY   4096

#define LEAK  0.45f
#define GAIN  0.48f
#define BURST 0.1f

float states[N_NEURONS];
float delay_buffer[N_NEURONS][MAX_DELAY];
int delay_idx = 0;

float weights[N_NEURONS][N_NEURONS];
int delays[N_NEURONS][N_NEURONS];

float randFloat() { return ((float)rand() / RAND_MAX) * 2.0f - 1.0f; }

void random_resonant_weights() {
  float w[N_NEURONS][N_NEURONS];
  float max_val = 0.0f;

  for(int i=0;i<N_NEURONS;i++){
    for(int j=0;j<N_NEURONS;j++){
      w[i][j] = randFloat();
      float a = fabs(w[i][j]);
      if(a > max_val) max_val = a;
    }
  }

  for(int i=0;i<N_NEURONS;i++){
    for(int j=0;j<N_NEURONS;j++){
      weights[i][j] = (w[i][j] / max_val) * GAIN;

      delays[i][j] = 1 + (int)(fabs(randFloat()) * (MAX_DELAY - 1));
      if(delays[i][j] < 1) delays[i][j] = 1;
      if(delays[i][j] >= MAX_DELAY) delays[i][j] = MAX_DELAY - 1;
    }
  }
}

I2S i2s_output(OUTPUT);

int16_t left_buffer[I2S_WORDS];
int16_t right_buffer[I2S_WORDS];

static inline uint32_t read_from_rosc() {
  uint32_t random = 0;
  volatile uint32_t *rnd_reg = (uint32_t *)(ROSC_BASE + ROSC_RANDOMBIT_OFFSET);
  for (int k = 0; k < 32; k++) {
    uint32_t bit = 0;
    while (1) {
      bit = (*rnd_reg) & 1;
      if (bit != ((*rnd_reg) & 1)) break;
    }
    random = (random << 1) | bit;
  }
  return random;
}

void seed_random_safe() {

  uint32_t seed = 0;
  for (int i = 0; i < 8; i++) {
    seed ^= read_from_rosc();
    delayMicroseconds(100);
  }
  srand(seed);
  randomSeed(seed);

}

void setup() {

  seed_random_safe();

  i2s_output.setFrequency(SAMPLE_RATE);
  i2s_output.setDATA(I2S_DATA_PIN);
  i2s_output.setBCLK(I2S_BCLK_PIN);
  i2s_output.setBitsPerSample(16);
  i2s_output.setBuffers(I2S_BUFFERS, I2S_WORDS);
  i2s_output.begin();
  
}

void loop() {

  for (uint32_t n = 0; n < I2S_WORDS; n++) {

    float x[N_NEURONS] = {0};

    for(int i=0;i<N_NEURONS;i++){
      for(int j=0;j<N_NEURONS;j++){
        int d = delays[i][j];
        int idx = (delay_idx - d + MAX_DELAY) % MAX_DELAY;
        x[i] += weights[i][j] * delay_buffer[j][idx];
      }
    }

    float valL = 0.0f;
    float valR = 0.0f;
    int cntL = 0;
    int cntR = 0;

    for(int i = 0; i < N_NEURONS; i++) {
      states[i] = LEAK * states[i] + tanhf(x[i]);
      delay_buffer[i][delay_idx] = states[i];

      if (i & 1) {
        valR += states[i];
        cntR++;
      } else {
        valL += states[i];
        cntL++;
      }
    }

    if (cntL > 0) valL /= cntL;
    if (cntR > 0) valR /= cntR;

    int16_t sampleL = (int16_t)(8192.0f * (1.0f + valL));
    int16_t sampleR = (int16_t)(8192.0f * (1.0f + valR));

    left_buffer[n]  = sampleL;
    right_buffer[n] = sampleR;

    i2s_output.write16(right_buffer[n], left_buffer[n]);

    delay_idx = (delay_idx + 1) % MAX_DELAY;

  }

}

void setup1() {

  seed_random_safe();

  for(int k = 1; k < MAX_DELAY; k++) {
    int d = (delay_idx + k) % MAX_DELAY;
    delay_buffer[0][d] += randFloat() * BURST;
  }

}

void loop1() {

  random_resonant_weights();

  int tempo = 60000 / BPM;
  delay(tempo);

}