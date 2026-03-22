// Stereo RNN recurrent neuronium resonator with reverb //

#include "hardware/structs/rosc.h"
#include <I2S.h>

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define I2S_WORDS     64
#define SAMPLE_RATE   44100

#define RNN_TAPS       4
#define NUM_NEURONS    8
#define NOISE_BURST    32

I2S i2s_output(OUTPUT);

float weights_L1[NUM_NEURONS][RNN_TAPS];
float weights_Inter[NUM_NEURONS][NUM_NEURONS];
float weights_L2[RNN_TAPS];

float feedback_L1[NUM_NEURONS][RNN_TAPS];
float last_outputs[NUM_NEURONS];
float feedback_L2[RNN_TAPS];

int half_neurons = NUM_NEURONS / 2;
float norm_L = 1.0f / (float)half_neurons;
float norm_R = 1.0f / (float)(NUM_NEURONS - half_neurons);

bool trigger = false;
int noise_timer = 0;

#define REV_LEN 4000
float rev_buf_L[REV_LEN];
float rev_buf_R[REV_LEN];
int rev_ptr = 0;
float rev_feedback = 0.65f;

float randomf(float min, float max) { return min + (max - min) * ((float)rand() / (float)RAND_MAX); }

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

  trigger = true;

}

void loop() {

  for (uint32_t i = 0; i < I2S_WORDS; i++) {

    float excitation = 0;
    if (trigger) { noise_timer = NOISE_BURST; trigger = false; }
    if (noise_timer > 0) {
      excitation = randomf(-1.0f, 1.0f);
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
      
      float out_n = tanhf(excitation + sum);

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
    
    float out_L2 = tanhf(((l1_left + l1_right) * 0.5f) + sum2);
    
    for (int j = RNN_TAPS - 1; j > 0; j--) feedback_L2[j] = feedback_L2[j-1];
    feedback_L2[0] = out_L2;

    float dryL = (l1_left * 0.6f + out_L2 * 0.4f);
    float dryR = (l1_right * 0.6f + out_L2 * 0.4f);

    float wetL = rev_buf_L[rev_ptr];
    float wetR = rev_buf_R[rev_ptr];

    rev_buf_L[rev_ptr] = dryL + (wetL * rev_feedback);
    rev_buf_R[rev_ptr] = dryR + (wetR * rev_feedback);
    
    if (++rev_ptr >= REV_LEN) rev_ptr = 0;

    int16_t sampleL = (int16_t)((dryL * 0.7f + wetL * 0.3f) * 4096.0f);
    int16_t sampleR = (int16_t)((dryR * 0.7f + wetR * 0.3f) * 4096.0f);

    i2s_output.write16(sampleL, sampleR);

  }

}

void setup1() {

  seed_random_safe();

}

void loop1() {

  for (int n = 0; n < NUM_NEURONS; n++) {

    for (int i = 0; i < RNN_TAPS; i++) {
      weights_L1[n][i] += randomf(-0.01f, 0.01f);
    }

    for (int m = 0; m < NUM_NEURONS; m++) {
      weights_Inter[n][m] += randomf(-0.01f, 0.01f);
    }

  }
  
  delay(10);

}