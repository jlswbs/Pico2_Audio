//  Faust DSP - Djembe random //

#include <I2S.h>
#include "djembe.h"

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define I2S_WORDS     64
#define SAMPLE_RATE   48000

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