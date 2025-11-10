// Simple digital Waveguide synthesis //

#include "hardware/structs/rosc.h"
#include <I2S.h>

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define I2S_WORDS     64

#define SAMPLE_RATE   44100
#define BPM           120
#define SIZE 512

I2S i2s_output(OUTPUT);

int16_t left_buffer[I2S_WORDS];
int16_t right_buffer[I2S_WORDS];

float leftWave[SIZE];
float rightWave[SIZE];

float lowpass = 0.9f;
float reflectL = -0.95f;
float reflectR = 0.95f;

float fractionalIdx = 0.0f;
float step = 1.0f;

uint16_t N = 128;

float lp1 = 0.0f, lp2 = 0.0f;
inline float lowpass2(float in) {
    lp1 = lp1 + lowpass * (in - lp1);
    lp2 = lp2 + lowpass * (lp1 - lp2);
    return lp2;
}

float readWave(float *buffer, float idx) {
    int i0 = (int)idx;
    int i1 = (i0 + 1) % SIZE;
    float frac = idx - i0;
    return buffer[i0]*(1.0f-frac) + buffer[i1]*frac;
}

enum ExciteType { NOISE, SINE };

void excite(float freq, ExciteType type = NOISE) {

    N = (uint16_t)(SAMPLE_RATE / freq);
    if (N >= SIZE) N = SIZE - 1;
    if (N < 4) N = 4;

    step = 1.0f;            
    fractionalIdx = 0.0f;    

    for (int i = 0; i < N; i++) {
        float s = 0.0f;
        switch(type) {
            case NOISE:
                s = (float)random(-32768, 32767) / 65536.0f;
                break;
            case SINE:
                s = sinf(2.0f * 3.14159265f * i / N);
                break;
        }
        rightWave[i] = s;
        leftWave[i]  = 0.0f;
    }

}

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

  for (uint32_t n = 0; n < I2S_WORDS; n++){

    float right = readWave(rightWave, fractionalIdx);
    float left  = readWave(leftWave, fractionalIdx);

    float out = right + left;

    float nextRight = lowpass2(left * reflectL);
    float nextLeft  = lowpass2(right * reflectR);

    int idx = (int)fractionalIdx;
    rightWave[idx] = nextRight;
    leftWave[idx]  = nextLeft;

    fractionalIdx += step;
    if (fractionalIdx >= N) fractionalIdx -= N;

    int16_t sample = (int16_t)(16383.0f * out);
    left_buffer[n]  = sample;
    right_buffer[n] = sample;

    i2s_output.write16(right_buffer[n], left_buffer[n]);

  }

}

void setup1() {

  seed_random_safe();

}

void loop1() {

  float freqTable[] = {110.0f, 146.8f, 196.0f, 246.9f, 329.6f, 392.0f, 440.0f, 523.3f};
  float f = freqTable[random(0, 8)];

  ExciteType type = (ExciteType)random(0, 2);
  excite(f, type);

  int tempo = 60000 / BPM;
  delay(tempo / 3);

}