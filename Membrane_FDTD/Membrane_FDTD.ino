// FDTD (Finite Difference Time Domain) membrane model //

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

#define NX 10
#define NY 10

float u[3][NX][NY];
float lambda2 = 0.001f;
float damping = 0.9995f;
float strike = 3.0f;
float amp = 0.0f;

float randomFloat(float min, float max) {
    return min + (max - min) * ((float)rand() / (float)RAND_MAX);
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

float membrane_step() {
  for (int x = 1; x < NX - 1; x++) {
    for (int y = 1; y < NY - 1; y++) {
      float laplacian =
        u[1][x + 1][y] + u[1][x - 1][y] +
        u[1][x][y + 1] + u[1][x][y - 1] -
        4.0f * u[1][x][y];

      u[2][x][y] = damping * (2.0f * u[1][x][y] - u[0][x][y] + lambda2 * laplacian);
    }
  }

  for (int x = 0; x < NX; x++) {
    for (int y = 0; y < NY; y++) {
      u[0][x][y] = u[1][x][y];
      u[1][x][y] = u[2][x][y];
    }
  }

  return u[1][NX / 2][NY / 2];
}

void strike_membrane(float strike, float amp) {
    int cx = NX / 2;
    int cy = NY / 2;

    for (int x = 0; x < NX; x++) {
        for (int y = 0; y < NY; y++) {
            float dx = x - cx;
            float dy = y - cy;
            float dist2 = dx * dx + dy * dy;
            float gain = expf(-dist2 / (2.0f * strike * strike));
            u[1][x][y] += amp * gain;
        }
    }
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
  
  for (uint32_t k = 0; k < I2S_WORDS; k++) {

    float s = membrane_step();
    int16_t sample = 256*s;

    left_buffer[k] = sample;
    right_buffer[k] = sample;

    i2s_output.write16(right_buffer[k], left_buffer[k]);
  }

}

void loop1() {

  strike = randomFloat(1.0f, 8.0f);
  amp = randomFloat(0.1f, 0.9f);
    
  strike_membrane(strike, amp);

  int tempo = 60000 / BPM;
  delay(tempo / 2);
  
}