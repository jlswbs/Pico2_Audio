// 6 MIM resonators (mass interaction model - RK2 Heun) //

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

class MIMResonator {

public:
  float x = 0.0f, v = 0.0f, force = 0.0f;
  float dt, m = 1.0f, k_lin = 0.0f, k_nonlin = 0.0f;
  float damping = 50.0f;
  float nonlin = 1e6;

  MIMResonator() {}

  void init(float sampleRate) {
    dt = 1.0f / sampleRate;
  }

  void trigger(float freq, float dmp, float f_impulse) {

    x = 0.0f;
    v = 0.0f;
    force = f_impulse; 
    damping = dmp; 
    k_lin = m * powf(2.0f * M_PI * freq, 2.0f);
    k_nonlin = k_lin * nonlin;

  }

  float getAcceleration(float cX, float cV, float cF) {

    float x3 = cX * cX * cX;
    float f_spring = -(k_lin * cX + k_nonlin * x3);
    float f_damping = damping * cV;
    return (cF + f_spring - f_damping) / m;

  }

  float process() {

    float a1 = getAcceleration(x, v, force);
    float x_pred = x + v * dt;
    float v_pred = v + a1 * dt;
    float a2 = getAcceleration(x_pred, v_pred, 0.0f);

    x = x + (v + v_pred) * 0.5f * dt;
    v = v + (a1 + a2) * 0.5f * dt;
    force = 0.0f;
    return x;

  }

};

MIMResonator bank[6];

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

  for(int i=0; i<6; i++) bank[i].init(SAMPLE_RATE);

  i2s_output.setFrequency(SAMPLE_RATE);
  i2s_output.setDATA(I2S_DATA_PIN);
  i2s_output.setBCLK(I2S_BCLK_PIN);
  i2s_output.setBitsPerSample(16);
  i2s_output.setBuffers(I2S_BUFFERS, I2S_WORDS);
  i2s_output.begin();

}

void loop() {

  for (uint32_t n = 0; n < I2S_WORDS; n++) {

    float mixed_out = 0;
    
    for(int i=0; i<6; i++) mixed_out += bank[i].process();

    float val = tanhf(mixed_out * 300.0f); 
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

  float base_freq = random(55, 880);
  float impulse = random(20000, 60000);

  for(int i=0; i<6; i++) {

    float dmp = 25.0f + (i * i * 15.0f); 
    float detune = base_freq * (1.0f + (i * 0.5f)); 

    bank[i].trigger(detune, dmp, impulse);

  }

  int tempo_ms = 60000 / BPM;
  delay(tempo_ms / 3);

}