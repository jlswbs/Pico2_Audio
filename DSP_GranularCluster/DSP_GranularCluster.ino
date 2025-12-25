// Granular N voices cluster //

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
  float pos  = phase * TABLE_SIZE;
  int   idx1 = (int)pos & (TABLE_SIZE - 1);
  int   idx2 = (idx1 + 1) & (TABLE_SIZE - 1);
  float frac = pos - (int)pos;
  return sin_table[idx1] * (1.0f - frac) + sin_table[idx2] * frac;
}

inline float hann(float x) { return 0.5f - 0.5f * cosf(2.0f * M_PI * x); }

struct GranularVoice {
  float tablePos;
  float grainSize;
  float grainCounter;
  float baseFreq;
  bool  active;

  GranularVoice()
    : tablePos(0.0f),
      grainSize(0.05f),
      grainCounter(0.0f),
      baseFreq(110.0f),
      active(false) {}

  void trigger(float frequency) {
    baseFreq     = frequency;
    grainSize    = random(1, 250) / 1000.0f;
    grainCounter = 0.0f;
    active       = true;
  }

  float process() {
    if (!active) return 0.0f;

    float grainSamples = grainSize * SAMPLE_RATE;
    if (grainCounter >= grainSamples) {
      active = false;
      return 0.0f;
    }

    float grainPos = grainCounter / grainSamples;

    int   idx1  = (int)tablePos & (TABLE_SIZE - 1);
    int   idx2  = (idx1 + 1) & (TABLE_SIZE - 1);
    float frac  = tablePos - (int)tablePos;
    float src   = sin_table[idx1] * (1.0f - frac) + sin_table[idx2] * frac;

    float env = hann(grainPos);

    tablePos += (baseFreq * TABLE_SIZE) / SAMPLE_RATE;
    if (tablePos >= TABLE_SIZE) tablePos -= TABLE_SIZE;

    grainCounter += 1.0f;

    return src * env * 0.8f;
  }
};

const int NUM_VOICES = 8;
float base_freq = 110.0f;
float step      = 1.0f;
GranularVoice voices[NUM_VOICES];

void setup() {

  seed_random_safe();

  for (int i = 0; i < TABLE_SIZE; i++) sin_table[i] = sinf(2.0f * M_PI * i / TABLE_SIZE);

  i2s_output.setFrequency(SAMPLE_RATE);
  i2s_output.setDATA(I2S_DATA_PIN);
  i2s_output.setBCLK(I2S_BCLK_PIN);
  i2s_output.setBitsPerSample(16);
  i2s_output.setBuffers(I2S_BUFFERS, I2S_WORDS);
  i2s_output.begin();

}

void loop() {

  for (uint32_t n = 0; n < I2S_WORDS; n++) {

    float mix = 0.0f;
    for (int v = 0; v < NUM_VOICES; v++) mix += voices[v].process();
    mix /= NUM_VOICES;
    int16_t sample = (int16_t)(mix * 16383.0f);

    left_buffer[n]  = sample;
    right_buffer[n] = sample;

    i2s_output.write16(right_buffer[n], left_buffer[n]);
  
  }

}

void setup1() {

  seed_random_safe();

}

void loop1() {

  step = random(1, 110) / 10.0f;
  base_freq = random(50, 880); 

  for (int v = 0; v < NUM_VOICES; v++) {
    float f = base_freq * powf(2.0f, v * step / 12.0f);
    if (!voices[v].active || random(0, 100) < 60) {
      voices[v].trigger(f);
    }
  }

  int tempo_ms = 60000 / BPM;
  delay(tempo_ms / 4);

}