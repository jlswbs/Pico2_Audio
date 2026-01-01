// RC stages analog kick drum //

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

const int STAGES = 200;
float stages[STAGES];
float outVal = 0.0f;
float lastInput = 0.0f;
float dcBlockState = 0.0f;
float feedback = 0.9997f;
float cutoff = 0.5f;
float gain = 25.0f;
float bias = 0.05f;
bool polarity = true;

float randomf(float minf, float maxf) { return minf + random(1UL << 31)*(maxf - minf) / (1UL << 31); }

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

    float input = stages[STAGES - 1] * feedback;
    float prev = input;
  
    for (int i = 0; i < STAGES; i++) {
      stages[i] += cutoff * (prev - stages[i]);
      if(polarity == true) prev = -stages[i];
      else prev = stages[i];
    }
  
    float currentStageOutput = stages[STAGES - 1];
    dcBlockState = currentStageOutput - lastInput + (0.995f * dcBlockState);
    lastInput = currentStageOutput;

    float val = tanhf(gain * (dcBlockState + bias));
    int16_t sample = (int16_t)(val * 8192.0f);

    left_buffer[n]  = sample;
    right_buffer[n] = sample;

    i2s_output.write16(right_buffer[n], left_buffer[n]);
  
  }

}

void setup1() {

  seed_random_safe();

}

void loop1() {

  for (int i = 0; i < STAGES; i++) stages[i] = randomf(-1.0f, 1.0f);
  cutoff = randomf(0.45f, 0.75f);

  int tempo_ms = 60000 / BPM;
  delay(tempo_ms / 3);

}