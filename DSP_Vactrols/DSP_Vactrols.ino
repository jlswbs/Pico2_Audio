// Vactrols harmonic membrane analog oscillator //

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

const int vactrols = 8;

float illum[vactrols];
float resistance[vactrols];
float state1[vactrols];
float state2[vactrols];
float excitation[vactrols];
float freq[vactrols];

const float Rmin = 0.01f;
const float Rmax = 1.0f;
const float tau_on  = 0.0012f;
const float tau_off = 0.035f;
const float feedback  = -1.0f;

#define TANH(x) ((x) * (27.0f + (x)*(x)) / (27.0f + 9.0f*(x)*(x)))


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

float randomFloat(float minVal, float maxVal) {
  return minVal + (maxVal - minVal) * ((float)random() / (float)RAND_MAX);
}

float vactrol_step(int i, float freq, float exc, float dt){

  float tau = (exc > illum[i]) ? tau_on : tau_off;
  if (tau <= 1e-8f) tau = tau_off;
  float alpha = 1.0f - expf(-dt / tau);
  illum[i] += alpha * (exc - illum[i]);

  resistance[i] = freq * (Rmin + (Rmax - Rmin) / (1.0f + 10.0f * powf(illum[i], 0.75f)));

  return resistance[i];

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

  const float dt = 1.0f / (float)SAMPLE_RATE;

  for (uint32_t n = 0; n < I2S_WORDS; n++){

    float out_sample = 0.0f;

    for (int i=0;i<vactrols;i++){

      float w0 = vactrol_step(i, freq[i], excitation[i], dt);
      float x = TANH(w0 * state1[i] + feedback * state2[i]);

      state2[i] = state1[i];
      state1[i] = x;

      out_sample += x;

    }

    out_sample /= vactrols;

    int16_t sample = (int16_t)(16383.0f * out_sample);
    left_buffer[n]  = sample;
    right_buffer[n] = sample;

    i2s_output.write16(right_buffer[n], left_buffer[n]);

  }

}

void setup1() {

  seed_random_safe();

}

void loop1() {

  for (int i=0;i<vactrols;i++){

    freq[i] = randomFloat(3.9f, 7.9f);
    state1[i] = randomFloat(-0.1f, 0.1f);
    state2[i] = randomFloat(-0.1f, 0.1f);
    excitation[i] = 0.207f;

  }

  int tempo = 60000 / BPM;
  delay(tempo / 3);

}