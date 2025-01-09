//  Faust DSP - Bubble //

#include <I2S.h>
#include "bubble.h"

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define I2S_WORDS     64
#define SAMPLE_RATE   48000

float randomf(float minf, float maxf) {return minf + (rand()%(1UL << 31))*(maxf - minf) / (1UL << 31);}

  I2S i2s_output(OUTPUT);
  mydsp* dsp;

  int16_t left_buffer[I2S_WORDS];
  int16_t right_buffer[I2S_WORDS];

void setup(){

  dsp = newmydsp();
  initmydsp(dsp, SAMPLE_RATE);

  analogReadResolution(12);
    
  i2s_output.setFrequency(SAMPLE_RATE);
  i2s_output.setDATA(I2S_DATA_PIN);
  i2s_output.setBCLK(I2S_BCLK_PIN);
  i2s_output.setBitsPerSample(16);
  i2s_output.setBuffers(I2S_BUFFERS, I2S_WORDS);
  i2s_output.begin();

}

void loop(){

  float left, right;
  FAUSTFLOAT* outputs[2] = { &left, &right };

  for (uint32_t i = 0; i < I2S_WORDS; i++) {
 
    computemydsp(dsp, 1, NULL, outputs);
    
    left_buffer[i] = 4096 * left;
    right_buffer[i] = 4096 * right;
    i2s_output.write16(left_buffer[i], right_buffer[i]);

  }

}

void loop1(){

  dsp->fHslider0 = random(110, 2000); // shape frequency Hz
  dsp->fHslider1 = randomf(0.4f, 0.99f); // gain 0..1
  dsp->fButton0 = 1.0f; // gate on

  delay(10);

  dsp->fButton0 = 0.0f; // gate off

  delay(230);

}