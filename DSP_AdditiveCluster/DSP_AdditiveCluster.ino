// Additive N voices cluster //

#include "hardware/structs/rosc.h"
#include <I2S.h>
#include <cmath>

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
float wave_table[TABLE_SIZE];

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

float lookup_wave(float phase) {

  float pos = phase * TABLE_SIZE;
  int idx1 = (int)pos % TABLE_SIZE;
  int idx2 = (idx1 + 1) % TABLE_SIZE;
  float frac = pos - (int)pos;
  
  return wave_table[idx1] * (1.0f - frac) + wave_table[idx2] * frac;

}

struct AdditiveVoice {
  float phase;
  float freq;
  float harmonics[8];
  bool active;
  
  AdditiveVoice() : phase(0.0f), freq(0.0f), active(false) {
    for (int i = 0; i < 8; i++) harmonics[i] = 0.0f;
  }
  
  void trigger(float frequency) {
    freq = frequency;
    for (int i = 0; i < 8; i++) harmonics[i] = 1.0f / (i + 1);
    active = true;
  }
  
  float process() {
    if (!active) return 0.0f;
    
    float sample = 0.0f;
    
    for (int i = 0; i < 8; i++) {
      float harmonicPhase = phase * (i + 1);
      if (harmonicPhase >= 1.0f) harmonicPhase -= (int)harmonicPhase;
      sample += harmonics[i] * lookup_wave(harmonicPhase);
    }
    
    phase += freq / SAMPLE_RATE;
    if (phase >= 1.0f) phase -= 1.0f;
    
    return sample * 0.3f;
  }
};

const int NUM_VOICES = 5;
float base_freq = 100.0f;
float step = 1.0f;
AdditiveVoice voices[NUM_VOICES];

void setup() {

  seed_random_safe();

  i2s_output.setFrequency(SAMPLE_RATE);
  i2s_output.setDATA(I2S_DATA_PIN);
  i2s_output.setBCLK(I2S_BCLK_PIN);
  i2s_output.setBitsPerSample(16);
  i2s_output.setBuffers(I2S_BUFFERS, I2S_WORDS);
  i2s_output.begin();

  for (int i = 0; i < TABLE_SIZE; i++) wave_table[i] = sinf(2.0f * M_PI * i / TABLE_SIZE);

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

  step = random(1, 50);
  
  for (int v=0; v<NUM_VOICES; v++) {

    float f = base_freq + v * step;
    voices[v].trigger(f);

  }

  int tempo = 60000 / BPM;
  delay(tempo);

}