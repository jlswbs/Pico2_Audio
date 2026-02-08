// Modal string model base a MIM resonators with wavetable exciter //

#include "hardware/structs/rosc.h"
#include <I2S.h>
#include "exciter.h"

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define I2S_WORDS     64

#define SAMPLE_RATE   44100
#define BPM           120
#define N_MODES       8
#define TABLE_SIZE    8192

I2S i2s_output(OUTPUT);

volatile float trigger_freq = 0;
const float BASE_FREQS[] = {98.0, 130.8, 196.0, 220.0, 360.0, 440.0, 660.0, 880.0};
int tone_idx = 0;
float gain = 70.0f;

struct ModalString {

  float x[N_MODES];
  float v[N_MODES];
  float ks[N_MODES];
  float cs[N_MODES];
  float m = 1.0f;
  float dt = 1.0f / (float)SAMPLE_RATE;
  float velocity = 1.0f;
  
  int sample_idx = 0;
  const int exciter_duration = TABLE_SIZE; 
    
  void trigger(float base_freq) {

    float decay_cs[] = {5.0f, 10.0f, 20.0f, 40.0f, 80.0f, 150.0f, 300.0f, 600.0f};

    sample_idx = 0;
    velocity = ((float)rand() / (float)RAND_MAX * 0.4f) + 0.8f;
    
    for (int i = 0; i < N_MODES; i++) {

      float freq = base_freq * (i + 1) * sqrtf(1.0f + (i + 1) * (i + 1) * 0.001f);
      ks[i] = m * powf(2.0f * M_PI * freq, 2);
      cs[i] = (i < 8) ? decay_cs[i] : decay_cs[7] * (i - 6);

    }

  }

  float process() {

    float force = 0.0f;
    if (sample_idx < exciter_duration) {
      force = wavetable[sample_idx] * (velocity * 10000.0f);
    }

    float total_x = 0.0f;
    for (int i = 0; i < N_MODES; i++) {
      float a = (force - ks[i] * x[i] - cs[i] * v[i]) / m;
      v[i] += a * dt;
      x[i] += v[i] * dt;
          
      if (x[i] > 2.0f) x[i] = 2.0f;
      if (x[i] < -2.0f) x[i] = -2.0f;

      total_x += x[i];
    }
    
    sample_idx++;
    return total_x;

  }

};


ModalString synth;

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

  if (trigger_freq > 0) {

    synth.trigger(trigger_freq);
    trigger_freq = 0;

  }

  for (uint32_t n = 0; n < I2S_WORDS; n++) {

    synth.process();

    float left_x = synth.x[0] + synth.x[1] + synth.x[3] + synth.x[5] + synth.x[7];
    float right_x = synth.x[0] + synth.x[2] + synth.x[4] + synth.x[6] + synth.x[7];

    int16_t sampleL = (int16_t)(tanhf(gain * left_x) * 8192.0f);
    int16_t sampleR = (int16_t)(tanhf(gain * right_x) * 8192.0f);

    i2s_output.write16(sampleL, sampleR);

  }

}

void setup1() {

  seed_random_safe();

}

void loop1() {
    
  trigger_freq = BASE_FREQS[tone_idx];
  tone_idx = rand() % 8;

  int tempo_ms = 60000 / BPM;
  delay(tempo_ms);

}