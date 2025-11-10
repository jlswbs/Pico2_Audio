// Simple digital Waveguide network synthesis //

#include "hardware/structs/rosc.h"
#include <I2S.h>

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define I2S_WORDS     64

#define SAMPLE_RATE   44100
#define BPM           120
#define SIZE 512
#define BRANCHES 4

I2S i2s_output(OUTPUT);

int16_t left_buffer[I2S_WORDS];
int16_t right_buffer[I2S_WORDS];

float wave[BRANCHES][SIZE];
float lowpass = 0.9f;

float reflect[BRANCHES] = {0.95f, -0.95f, 0.9f, -0.9f};

float fractionalIdx[BRANCHES];
float step[BRANCHES];
uint16_t N[BRANCHES];

float lp[BRANCHES] = {0.0f,0.0f,0.0f,0.0f};

inline float lowpass2(float in, int branch) {
    lp[branch] = lp[branch] + lowpass * (in - lp[branch]);
    return lp[branch];
}

float readWave(float *buffer, float idx) {
    int i0 = (int)idx;
    int i1 = (i0 + 1) % SIZE;
    float frac = idx - i0;
    return buffer[i0]*(1.0f-frac) + buffer[i1]*frac;
}

enum ExciteType { NOISE, SINE };

void excite(float freq, ExciteType type = NOISE) {
    for (int b=0;b<BRANCHES;b++){
        N[b] = (uint16_t)(SAMPLE_RATE / freq * (0.9f + 0.1f*b));
        if (N[b] >= SIZE) N[b] = SIZE-1;
        if (N[b] < 4) N[b] = 4;

        step[b] = 1.0f;            
        fractionalIdx[b] = 0.0f;    

        for (int i = 0; i < N[b]; i++) {
            float s = 0.0f;
            switch(type) {
                case NOISE:
                    s = (float)random(-32768, 32767) / 65536.0f;
                    break;
                case SINE:
                    s = sinf(2.0f * 3.14159265f * i / N[b]);
                    break;
            }
            wave[b][i] = s;
        }
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
    float out = 0.0f;

    for (int b=0;b<BRANCHES;b++){
      float val = readWave(wave[b], fractionalIdx[b]);
      out += val;

      float nextVal = lowpass2(val * reflect[b], b);
      int idx = (int)fractionalIdx[b];
      wave[b][idx] = nextVal;

      fractionalIdx[b] += step[b];
      if (fractionalIdx[b] >= N[b]) fractionalIdx[b] -= N[b];
    }

    int16_t sample = (int16_t)(16383.0f * out / BRANCHES);
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