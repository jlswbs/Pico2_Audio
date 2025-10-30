// Perceptrons harmonic modal oscillator //

#include "hardware/structs/rosc.h"
#include <I2S.h>

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define I2S_WORDS     64

#define SAMPLE_RATE   44100
#define BPM           120

I2S i2s_output(OUTPUT);

int16_t left_buffer[I2S_WORDS];
int16_t right_buffer[I2S_WORDS];

const int perceptrons = 16;
float alpha = 0.15f;

float Ws[perceptrons][2];
float Bs[perceptrons];
float states[perceptrons];
float states2[perceptrons];

float W_out[perceptrons];
float B_out = 0.0f;

static float outputs_hold[perceptrons];
static int decim_count = 0;

#define TANH(x) ((x) * (27.0f + (x)*(x)) / (27.0f + 9.0f*(x)*(x)))

float randomFloat(float minVal, float maxVal) {
  return minVal + (maxVal - minVal) * ((float)random() / (float)RAND_MAX);
}

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

void setup1() {

  seed_random_safe();

}

void loop() {

  for (uint32_t n = 0; n < I2S_WORDS; n++) {

    for (int p = 0; p < perceptrons; p++) {
        
      float x_prev  = states[p];
      float x_prev2 = states2[p];
      float w0 = Ws[p][0];
      float w1 = Ws[p][1];
      float b  = Bs[p];

      float x = TANH(w0 * x_prev + w1 * x_prev2 + b + TANH(x));

      states2[p] = x_prev;
      states[p]  = x;
      outputs_hold[p] = x;
      
    }

    float sum = 0.0f;
    for (int i = 0; i < perceptrons; i++) sum += W_out[i] * outputs_hold[i];
    float out_sample = TANH(sum + B_out);

    float y = y + alpha * (out_sample - y);

    int16_t sample = (int16_t)(8192.0f * y);

    left_buffer[n] = sample;
    right_buffer[n] = sample;
    i2s_output.write16(right_buffer[n], left_buffer[n]);

  }

}

void loop1() {

  for(int i=0; i<perceptrons; i++){

    Ws[i][0] = randomFloat(-1.0f, 1.0f);
    Ws[i][1] = -1.0f;
    Bs[i]    = 0.0f;
    states[i]  = randomFloat(-0.1f, 0.1f);
    states2[i] = randomFloat(-0.1f, 0.1f);
    W_out[i]   = randomFloat(-1.0f, 1.0f);

  }

  int tempo = 60000 / BPM;
  delay(tempo / 3);
  
}