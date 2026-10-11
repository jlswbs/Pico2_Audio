// Stereo RNN autopoiesis resonator with global drive //

#include "hardware/structs/rosc.h"
#include <I2S.h>

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define I2S_WORDS     64
#define SAMPLE_RATE   44100

#define RNN_TAPS       5
#define NUM_NEURONS    12
#define NOISE_BURST    16

I2S i2s_output(OUTPUT);

float weights_L1[NUM_NEURONS][RNN_TAPS];
float weights_Inter[NUM_NEURONS][NUM_NEURONS];
float weights_L2[RNN_TAPS];

float feedback_L1[NUM_NEURONS][RNN_TAPS];
float last_outputs[NUM_NEURONS];
float feedback_L2[RNN_TAPS];
float neuron_alpha[NUM_NEURONS];

int half_neurons = NUM_NEURONS / 2;
float norm_L = 1.0f / (float)half_neurons;
float norm_R = 1.0f / (float)(NUM_NEURONS - half_neurons);

bool trigger = false;
int noise_timer = 0;

float randomf(float min, float max) { return min + (max - min) * ((float)rand() / (float)RAND_MAX); }

static inline float fast_tanhf(float x) {

  if (x >= 3.0f) return 1.0f;
  if (x <= -3.0f) return -1.0f;
  return x * (27.0f + x * x) / (27.0f + 9.0f * x * x);

}

static inline uint32_t read_from_rosc() {

  uint32_t random_val = 0;
  volatile uint32_t *rnd_reg = (uint32_t *)(ROSC_BASE + ROSC_RANDOMBIT_OFFSET);
  for (int k = 0; k < 32; k++) {
    random_val = (random_val << 1) | ((*rnd_reg) & 1);
  }
  return random_val;

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

  for (int n = 0; n < NUM_NEURONS; n++) {
    last_outputs[n] = 0;
    for (int i = 0; i < RNN_TAPS; i++) {
      weights_L1[n][i] = randomf(-0.9f, 0.9f);
      feedback_L1[n][i] = 0.0f;
    }
    for (int m = 0; m < NUM_NEURONS; m++) {
      weights_Inter[n][m] = randomf(-0.5f, 0.5f);
    }
  }

  for (int i = 0; i < RNN_TAPS; i++) {
    weights_L2[i] = randomf(-0.9f, 0.9f);
    feedback_L2[i] = 0.0f;
  }

  for (int n = 0; n < NUM_NEURONS; n++) {
    neuron_alpha[n] = randomf(0.0005f, 0.2f); 
    if (n == 0) neuron_alpha[n] = 1.0f;
  }

  trigger = true;

}

void loop() {

  for (uint32_t i = 0; i < I2S_WORDS; i++) {

    float excitation = 0;
    static float env = 1.0f;

    if (trigger) {
      noise_timer = NOISE_BURST;
      env = 1.0f;
      trigger = false;
    }

    if (noise_timer > 0) {
      excitation = randomf(-1.0f, 1.0f) * env;
      env *= 0.85f;
      noise_timer--;
    }

    float l1_left = 0;
    float l1_right = 0;
    float current_outputs[NUM_NEURONS];

    for (int n = 0; n < NUM_NEURONS; n++) {

      float sum = 0;

      for (int j = 0; j < RNN_TAPS; j++) {
        sum += feedback_L1[n][j] * weights_L1[n][j];
      }
      
      for (int m = 0; m < NUM_NEURONS; m++) {
        sum += last_outputs[m] * weights_Inter[n][m];
      }
      
      float target_out = fast_tanhf(excitation + sum);
      float out_n = last_outputs[n] + neuron_alpha[n] * (target_out - last_outputs[n]);

      for (int j = RNN_TAPS - 1; j > 0; j--) feedback_L1[n][j] = feedback_L1[n][j-1];
      feedback_L1[n][0] = out_n;

      current_outputs[n] = out_n;

      if (n < half_neurons) l1_left += out_n;
      else                  l1_right += out_n;
  
    }
    
    for(int n=0; n<NUM_NEURONS; n++) last_outputs[n] = current_outputs[n];

    l1_left *= norm_L;
    l1_right *= norm_R;

    float sum2 = 0;
    for (int j = 0; j < RNN_TAPS; j++) {
      sum2 += feedback_L2[j] * weights_L2[j];
    }
    
    float out_L2 = fast_tanhf(((l1_left + l1_right) * 0.5f) + sum2);
    
    for (int j = RNN_TAPS - 1; j > 0; j--) feedback_L2[j] = feedback_L2[j-1];
    feedback_L2[0] = out_L2;

    int16_t sampleL = (int16_t)(last_outputs[0] * 8192.0f);
    int16_t sampleR = (int16_t)(last_outputs[NUM_NEURONS / 2] * 8192.0f);

    i2s_output.write16(sampleL, sampleR);

  }

}

void setup1() {

  seed_random_safe();

}

void loop1() {

  float total_energy = 0.0f;
  for (int n = 0; n < NUM_NEURONS; n++) {
    total_energy += fabsf(last_outputs[n]);
  }
  total_energy /= (float)NUM_NEURONS;

  float force_drive = 0.0f;
  float mutation_speed = 0.02f;

  if (total_energy < 0.15f) {
    force_drive = 0.005f; 
    mutation_speed = 0.04f; 
  } 
  else if (total_energy > 0.55f) {
    force_drive = -0.008f; 
    mutation_speed = 0.01f;
  }

  for (int n = 0; n < NUM_NEURONS; n++) {

    for (int i = 0; i < RNN_TAPS; i++) {

      float mut = randomf(-mutation_speed, mutation_speed);

      if (force_drive < 0) weights_L1[n][i] *= (1.0f + force_drive); 
      else                  weights_L1[n][i] += (weights_L1[n][i] > 0 ? force_drive : -force_drive);
      
      weights_L1[n][i] += mut;
      
      if (weights_L1[n][i] > 1.5f)  weights_L1[n][i] = 1.5f;
      if (weights_L1[n][i] < -1.5f) weights_L1[n][i] = -1.5f;

    }

    for (int m = 0; m < NUM_NEURONS; m++) {
      float mut = randomf(-mutation_speed, mutation_speed);
      
      if (force_drive < 0) weights_Inter[n][m] *= (1.0f + force_drive);
      else                  weights_Inter[n][m] += (weights_Inter[n][m] > 0 ? force_drive : -force_drive);
      
      weights_Inter[n][m] += mut;

      if (weights_Inter[n][m] > 1.2f)  weights_Inter[n][m] = 1.2f;
      if (weights_Inter[n][m] < -1.2f) weights_Inter[n][m] = -1.2f;
    }

  }
  
  delay(15);

}