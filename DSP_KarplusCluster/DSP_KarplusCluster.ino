// Karplus-Strong N voices cluster //

#include "hardware/structs/rosc.h"
#include <I2S.h>
#include <vector>

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define I2S_WORDS     64

#define SAMPLE_RATE   44100
#define BPM           120

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

void seed_random_safe(){

  uint32_t seed = 0;
  for (int i=0;i<8;i++){
    seed ^= read_from_rosc();
    delayMicroseconds(100);
  }
  srand(seed);
  randomSeed(seed);

}

struct KSVoice {
  std::vector<float> buffer;
  int idx;
  float decay;
  bool active;

  KSVoice() : idx(0), decay(0.996f), active(false) {}

  void trigger(float freq) {
    int N = SAMPLE_RATE / freq;
    buffer.resize(N);
    for (int i=0;i<N;i++) buffer[i] = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
    idx = 0;
    active = true;
  }

  float process() {
    if (!active || buffer.empty()) return 0.0f;
    float out = buffer[idx];
    int next = (idx+1) % buffer.size();
    float avg = decay * 0.5f * (buffer[idx] + buffer[next]);
    buffer[idx] = avg;
    idx = next;
    return out;
  }
};

const int NUM_VOICES = 8;
float base_freq = 50.0f;
float step = 1.0f;
KSVoice voices[NUM_VOICES];


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

  for (uint32_t n = 0; n < I2S_WORDS; n++){

    float mix = 0.0f;
    for (int v=0; v<NUM_VOICES; v++) mix += voices[v].process();
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

  step = random(1, 50);
  
  for (int v=0; v<NUM_VOICES; v++) {

    float f = base_freq + v * step;
    voices[v].trigger(f);

  }

  int tempo = 60000 / BPM;
  delay(tempo);

}