// PureData oscillator noise kick noodle - 250MHz CPU speed //

#include <I2S.h>
#include "Heavy_prog.hpp"

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define I2S_WORDS     64
#define SAMPLE_RATE   22050

class Trand {

  public: Trand();

};

Trand::Trand() {
  
  uint32_t random = 0;
  uint32_t random_bit;
  volatile uint32_t *rnd_reg = (uint32_t *)(ROSC_BASE + ROSC_RANDOMBIT_OFFSET);

  for (int k = 0; k < 32; k++) {
    while (1) {
      random_bit = (*rnd_reg) & 1;
      if (random_bit != ((*rnd_reg) & 1)) break;
    }

    random = (random << 1) | random_bit;
  }
  
  srand(random);

}

  Trand Trand;
  I2S i2s_output(OUTPUT);
  Heavy_prog pd_prog(SAMPLE_RATE);

  float samples[2 * I2S_WORDS];
  int16_t left_buffer[I2S_WORDS];
  int16_t right_buffer[I2S_WORDS];

void setup() {

  i2s_output.setFrequency(SAMPLE_RATE);
  i2s_output.setDATA(I2S_DATA_PIN);
  i2s_output.setBCLK(I2S_BCLK_PIN);
  i2s_output.setBitsPerSample(16);
  i2s_output.setBuffers(I2S_BUFFERS, I2S_WORDS);
  i2s_output.begin();

}

void loop() {

  pd_prog.processInlineInterleaved(samples, samples, I2S_WORDS);

  for (uint32_t i = 0; i < I2S_WORDS; i++) {
    
    left_buffer[i] = 2048 * samples[2*i];
    right_buffer[i] = 2048 * samples[2*i+1];
    i2s_output.write16(right_buffer[i], left_buffer[i]);

  }

}