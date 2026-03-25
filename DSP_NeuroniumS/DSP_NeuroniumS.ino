// Stereo SNN spike neuronium resonator and reverb //

#include "hardware/structs/rosc.h"
#include <I2S.h>

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define I2S_WORDS     64
#define SAMPLE_RATE   44100

#define NUM_TAPS       4
#define NUM_NEURONS    8
#define NOISE_BURST    512

#define MEMBRANE_LEAK   0.995f
#define SPIKE_THRESHOLD 0.9f
#define SPIKE_RESET     0.0f
#define REFRACTORY_MS   2
#define SPIKE_STRENGTH  0.75f

I2S i2s_output(OUTPUT);

struct SpikeNeuron {

  float membrane;
  int refractory_counter;
  bool just_spiked;
  
  void init() {
    membrane = 0;
    refractory_counter = 0;
    just_spiked = false;
  }
  
  bool update(float input) {
    just_spiked = false;
    
    if (refractory_counter > 0) {
      refractory_counter--;
      membrane = SPIKE_RESET;
      return false;
    }
    
    membrane = membrane * MEMBRANE_LEAK + input;
    
    if (membrane >= SPIKE_THRESHOLD) {
      membrane = SPIKE_RESET;
      refractory_counter = (REFRACTORY_MS * SAMPLE_RATE) / 1000;
      just_spiked = true;
      return true;
    }
    
    return false;
  }

};

SpikeNeuron neurons[NUM_NEURONS];
SpikeNeuron output_neuron;

float weights_TAPS[NUM_NEURONS][NUM_TAPS];
float weights_Inter[NUM_NEURONS][NUM_NEURONS];
float weights_Output[NUM_TAPS];

float feedback_TAPS[NUM_NEURONS][NUM_TAPS];
float feedback_Output[NUM_TAPS];

int last_spike_time[NUM_NEURONS];
float spike_trace[NUM_NEURONS];

bool trigger = false;
int noise_timer = 0;

int half_neurons = NUM_NEURONS / 2;
float norm_L = 1.0f / (float)half_neurons;
float norm_R = 1.0f / (float)(NUM_NEURONS - half_neurons);

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
    neurons[n].init();
    last_spike_time[n] = -1000;
    spike_trace[n] = 0;
  }

  output_neuron.init();
  
  float scale_taps = 1.0f / sqrtf((float)NUM_TAPS);
  float scale_inter = 1.0f / sqrtf((float)NUM_NEURONS);
  float scale_output = 1.0f / sqrtf((float)NUM_TAPS);
  
  for (int n = 0; n < NUM_NEURONS; n++) {
    for (int i = 0; i < NUM_TAPS; i++) {
      weights_TAPS[n][i] = randomf(-1.0f, 1.0f) * scale_taps;
      feedback_TAPS[n][i] = 0;
    }
    for (int m = 0; m < NUM_NEURONS; m++) {
      weights_Inter[n][m] = randomf(-1.0f, 1.0f) * scale_inter;
    }
  }
  
  for (int i = 0; i < NUM_TAPS; i++) {
    weights_Output[i] = randomf(-1.0f, 1.0f) * scale_output;
    feedback_Output[i] = 0;
  }
  
  trigger = true;

}

void loop() {
  
  static float spike_audio_L = 0, spike_audio_R = 0;
  static float spike_energy_L = 0, spike_energy_R = 0;
  
  for (uint32_t sample = 0; sample < I2S_WORDS; sample++) {
    
    float excitation = 0;
    if (trigger) { 
      noise_timer = NOISE_BURST; 
      trigger = false; 
    }
    if (noise_timer > 0) {
      excitation = randomf(-1.0f, 1.0f);
      noise_timer--;
    }
    
    float left_spike_density = 0;
    float right_spike_density = 0;
    
    for (int n = 0; n < NUM_NEURONS; n++) {
      
      float sum = excitation;
      
      for (int j = 0; j < NUM_TAPS; j++) {
        sum += feedback_TAPS[n][j] * weights_TAPS[n][j];
      }
      
      for (int m = 0; m < NUM_NEURONS; m++) {
        sum += spike_trace[m] * weights_Inter[n][m];
      }
      
      bool spike = neurons[n].update(sum);
      
      spike_trace[n] = spike_trace[n] * 0.985f;
      if (spike) {
        spike_trace[n] += SPIKE_STRENGTH;
        last_spike_time[n] = sample;
        
        float spike_impulse = 0.3f;
        if (n < half_neurons) {
          left_spike_density += spike_impulse;
        } else {
          right_spike_density += spike_impulse;
        }
      }
      
      float tap_value = spike_trace[n];
      for (int j = NUM_TAPS - 1; j > 0; j--) {
        feedback_TAPS[n][j] = feedback_TAPS[n][j-1];
      }
      feedback_TAPS[n][0] = tap_value;
    }
    
    left_spike_density /= (float)half_neurons;
    right_spike_density /= (float)(NUM_NEURONS - half_neurons);
    
    float sum2 = 0;
    for (int j = 0; j < NUM_TAPS; j++) {
      sum2 += feedback_Output[j] * weights_Output[j];
    }

    float output_input = ((left_spike_density + right_spike_density) * 0.5f) + sum2 * 0.3f;
    bool output_spike = output_neuron.update(output_input);
    
    float output_tap = (output_spike) ? 1.0f : 0.0f;
    for (int j = NUM_TAPS - 1; j > 0; j--) {
      feedback_Output[j] = feedback_Output[j-1];
    }
    feedback_Output[0] = output_tap;
    
    static float spike_envelope_L = 0, spike_envelope_R = 0;
    float envelope_decay = 0.97f;
    
    if (left_spike_density > 0) {
      spike_envelope_L += left_spike_density * 0.5f;
    }
    spike_envelope_L *= envelope_decay;
    
    if (right_spike_density > 0) {
      spike_envelope_R += right_spike_density * 0.5f;
    }
    spike_envelope_R *= envelope_decay;
    
    static float filtered_L = 0, filtered_R = 0;
    float spike_signal_L = (left_spike_density > 0) ? 1.0f : 0.0f;
    float spike_signal_R = (right_spike_density > 0) ? 1.0f : 0.0f;
    
    filtered_L = filtered_L * 0.95f + spike_signal_L * 0.1f;
    filtered_R = filtered_R * 0.95f + spike_signal_R * 0.1f;
    
    float dryL = spike_envelope_L * 0.6f + filtered_L * 0.4f;
    float dryR = spike_envelope_R * 0.6f + filtered_R * 0.4f;
    
    if (output_spike) {
      dryL += 0.5f;
      dryR += 0.5f;
    }
    
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

    for (int i = 0; i < NUM_TAPS; i++) {
      weights_TAPS[n][i] += randomf(-0.015f, 0.015f);
    }
    for (int m = 0; m < NUM_NEURONS; m++) {
      weights_Inter[n][m] += randomf(-0.015f, 0.015f);
    }

  }
  
  delay(100);

}