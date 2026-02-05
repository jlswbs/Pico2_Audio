// 6 coupled MIM resonators (mass interaction model - RK2 Heun) //

#include "hardware/structs/rosc.h"
#include <I2S.h>

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define I2S_WORDS     64

#define SAMPLE_RATE   44100
#define BPM           120

I2S i2s_output(OUTPUT);

class MIMResonator {

public:
  float x = 0.0f, v = 0.0f, force = 0.0f;
  float external_force = 0.0f;
  float dt, m = 1.0f, k_lin = 0.0f, k_nonlin = 0.0f;
  float damping = 50.0f;
  float nonlin = 1e6;

  MIMResonator() {}

  void init(float sampleRate) {
    dt = 1.0f / sampleRate;
  }

  void trigger(float freq, float dmp, float f_impulse) {
    force += f_impulse; 
    damping = dmp; 
    k_lin = m * powf(2.0f * M_PI * freq, 2.0f);
    k_nonlin = k_lin * nonlin;
  }

  float getAcceleration(float cX, float cV, float cF) {
    float x3 = cX * cX * cX;
    float f_spring = -(k_lin * cX + k_nonlin * x3);
    float f_damping = damping * cV;
    return (cF + external_force + f_spring - f_damping) / m;
  }

  void update_k1() {
    float a1 = getAcceleration(x, v, force);
    v_pred = v + a1 * dt;
    x_pred = x + v * dt;
    last_a1 = a1;
    force = 0;
  }

  void update_k2(float next_ext_force) {
    float old_ext = external_force;
    external_force = next_ext_force;
    float a2 = getAcceleration(x_pred, v_pred, 0.0f);
    x = x + (v + v_pred) * 0.5f * dt;
    v = v + (last_a1 + a2) * 0.5f * dt;
    external_force = old_ext;
  }

private:
  float x_pred, v_pred, last_a1;
};

MIMResonator bank[6];

float coupling_matrix = 50000.0f;

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
    
    for(int i=0; i<6; i++) {

      float total_ext = 0;
      for(int j=0; j<6; j++) { if(i != j) total_ext += (bank[j].x - bank[i].x) * coupling_matrix; }
      bank[i].external_force = total_ext;
      bank[i].update_k1();

    }

    for(int i=0; i<6; i++) {

      float total_ext_pred = 0;
      for(int j=0; j<6; j++) { if(i != j) total_ext_pred += (bank[j].x - bank[i].x) * coupling_matrix; }
      bank[i].update_k2(total_ext_pred);

    }

    float outL = 0;
    float outR = 0;
    
    for(int i=0; i<6; i++) {

      if(i % 2 == 0) outL += bank[i].x;
      else           outR += bank[i].x;

    }

    int16_t sampleL = (int16_t)(tanhf(outL * 800.0f) * 8192.0f);
    int16_t sampleR = (int16_t)(tanhf(outR * 800.0f) * 8192.0f);

    i2s_output.write16(sampleL, sampleR);

  }

}

void setup1() { 
  
  seed_random_safe(); 
  
}

void loop1() {

  int target = random(0, 6);
  float freq = random(55, 660);
  float dmp = random(15, 80);
  float impulse = random(30000, 70000);

  bank[target].trigger(freq, dmp, impulse);

  int tempo_ms = 60000 / BPM;
  delay(tempo_ms / 3);

}