// Formant N voices cluster //

#include "hardware/structs/rosc.h"
#include <I2S.h>

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define I2S_WORDS     64

#define SAMPLE_RATE   44100
#define BPM           120
#define TABLE_SIZE    1024

I2S i2s_output(OUTPUT);

int16_t left_buffer[I2S_WORDS];
int16_t right_buffer[I2S_WORDS];
float sin_table[TABLE_SIZE];

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

float fast_sin(float phase) {

  phase = phase - floorf(phase);
  float pos = phase * TABLE_SIZE;
  int idx1 = (int)pos % TABLE_SIZE;
  int idx2 = (idx1 + 1) % TABLE_SIZE;
  float frac = pos - (int)pos;
  return sin_table[idx1] * (1.0f - frac) + sin_table[idx2] * frac;

}

float fast_cos(float phase) { return fast_sin(phase + 0.25f); }

struct FormantVoice {
  float phase;
  float freq;
  float formants[3];
  float bandwidths[3];
  float z1[3];
  float z2[3];
  bool active;

  FormantVoice() : phase(0.0f), freq(0.0f), active(false) {
    formants[0] = 800.0f;
    formants[1] = 1150.0f;
    formants[2] = 2900.0f;

    bandwidths[0] = 80.0f;
    bandwidths[1] = 90.0f;
    bandwidths[2] = 120.0f;

    for (int i = 0; i < 3; i++) {
      z1[i] = 0.0f;
      z2[i] = 0.0f;
    }
  }

  void trigger(float frequency) {
    freq = frequency;

    formants[0] = random(300, 1000);
    formants[1] = random(800, 2500);
    formants[2] = random(2000, 4000);

    active = true;
  }

  float formantFilter(float x, int i) {

    float f  = formants[i] / SAMPLE_RATE;
    float bw = bandwidths[i] / SAMPLE_RATE;

    float R = expf(-M_PI * bw);
    float c = 2.0f * R * fast_cos(f);

    float y = (1.0f - R) * x
            + c * z1[i]
            - (R * R) * z2[i];

    z2[i] = z1[i];
    z1[i] = y;

    return 2.5f * y;

  }

  float process() {
    if (!active) return 0.0f;

    float excitation;

    if (random(100) > 30) {
      excitation = fast_sin(phase) * 0.6f;
    } else {
      excitation = (((float)rand() / RAND_MAX) * 2.0f - 1.0f) * 0.3f;
    }

    float y = excitation;
    y = formantFilter(y, 0);
    y = formantFilter(y, 1);
    y = formantFilter(y, 2);

    phase += freq / SAMPLE_RATE;
    if (phase >= 1.0f) phase -= 1.0f;

    return y;
  }
};

const int NUM_VOICES = 3;
float base_freq = 110.0f;
float step = 1.0f;
FormantVoice voices[NUM_VOICES];

void setup() {

  seed_random_safe();

  i2s_output.setFrequency(SAMPLE_RATE);
  i2s_output.setDATA(I2S_DATA_PIN);
  i2s_output.setBCLK(I2S_BCLK_PIN);
  i2s_output.setBitsPerSample(16);
  i2s_output.setBuffers(I2S_BUFFERS, I2S_WORDS);
  i2s_output.begin();

  for (int i = 0; i < TABLE_SIZE; i++) sin_table[i] = sinf(2.0f * M_PI * i / TABLE_SIZE);
  
}

void loop() {

  for (uint32_t n = 0; n < I2S_WORDS; n++) {

    float mix = 0.0f;
    for (int v = 0; v < NUM_VOICES; v++) mix += voices[v].process();
    mix /= NUM_VOICES;
    int16_t sample = (int16_t)(mix * 16383.0f);
    
    left_buffer[n] = sample;
    right_buffer[n] = sample;
    
    i2s_output.write16(right_buffer[n], left_buffer[n]);

  }

}

void setup1() {

  seed_random_safe();

}

void loop1() {

  step = random(1, 100);
  
  for (int v=0; v<NUM_VOICES; v++) {

    float f = base_freq + v * step;
    voices[v].trigger(f);

  }

  int tempo = 60000 / BPM;
  delay(tempo);

}