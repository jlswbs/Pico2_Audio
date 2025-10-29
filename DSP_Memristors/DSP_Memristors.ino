// Memristors harmonic analog oscillator //

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

const int memristors = 16;

float R[memristors];
float states[memristors];
float states2[memristors];

const float Rmin = 0.1f;
const float Rmax = 1.0f;
const float k = 0.001f;

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

    float out_sample = 0.0f;

    for(int i=0; i<memristors; i++){

      float x_prev  = states[i];
      float x_prev2 = states2[i];

      float w0 = 1.0f / R[i];
      float w1 = -1.0f;

      float x = TANH(w0*x_prev + w1*x_prev2);

      states2[i] = x_prev;
      states[i]  = x;

      float dR = k * x;
      R[i] += dR;
      if(R[i] < Rmin) R[i] = Rmin;
      if(R[i] > Rmax) R[i] = Rmax;

      out_sample += x;
  
    }

    out_sample /= memristors;

    int16_t sample = (int16_t)(16383.0f * out_sample);

    left_buffer[n] = sample;
    right_buffer[n] = sample;

    i2s_output.write16(right_buffer[n], left_buffer[n]);

  }

}

void loop1() {

  for(int i=0; i<memristors; i++){

    R[i] = randomFloat(0.53f, 0.85f);
    states[i]  = randomFloat(-0.1f, 0.1f);
    states2[i] = randomFloat(-0.1f, 0.1f);

  }

  int tempo = 60000 / BPM;
  delay(tempo / 3);
  
}