// Harmonic oscillator - https://github.com/assemblu/ApalisLite //

#include <I2S.h>
#include "harmonic.h"

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define I2S_WORDS     64
#define SAMPLE_RATE   44100
#define BPM           120
#define HARMONICS     16

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
  HarmonicOscillator osc;

  int16_t left_buffer[I2S_WORDS];
  int16_t right_buffer[I2S_WORDS];

void setup() {

  analogReadResolution(12);

  i2s_output.setFrequency(SAMPLE_RATE);
  i2s_output.setDATA(I2S_DATA_PIN);
  i2s_output.setBCLK(I2S_BCLK_PIN);
  i2s_output.setBitsPerSample(16);
  i2s_output.setBuffers(I2S_BUFFERS, I2S_WORDS);
  i2s_output.begin();

  osc.Init(SAMPLE_RATE);
  for (int i = 0; i < HARMONICS; ++i) osc.SetSingleAmp(1.0f/HARMONICS, i);
  osc.SetFirstHarmIdx(1);
  osc.SetFreq(220.f);

}

void loop() {

  for (uint32_t i = 0; i < I2S_WORDS; i++) {

    int16_t sample = 2048 * osc.Process();
    
    left_buffer[i] = sample;
    right_buffer[i] = sample;
    i2s_output.write16(right_buffer[i], left_buffer[i]);

  }

}

void loop1(){

  osc.SetFirstHarmIdx(random(1, HARMONICS));

  int tempo = 60000 / BPM;
  delay(tempo / 2);

}