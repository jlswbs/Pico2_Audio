// FFT stereo spectral sweep drone //

#define FIX32_FFT_IMPLEMENTATION

#include "hardware/structs/rosc.h"
#include <I2S.h>
#include "fix32_fft.h"

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define I2S_WORDS     64
#define SAMPLE_RATE   44100
#define FFT_SIZE      512
#define FFT_LOG2      9
#define FFT_BINS      256
#define AMP_SCALE     (65536 / FFT_BINS)

I2S i2s_output(OUTPUT);

int16_t audioBufferA[FFT_SIZE * 2];
int16_t audioBufferB[FFT_SIZE * 2];
volatile int16_t* volatile playBuffer = audioBufferA;
volatile int16_t* volatile fillBuffer = audioBufferB;
volatile bool readyToSwap = false;
int32_t vRealL[FFT_SIZE], vImagL[FFT_SIZE];
int32_t vRealR[FFT_SIZE], vImagR[FFT_SIZE];

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

}

void loop() {

  for (uint32_t i = 0; i < I2S_WORDS; i++) {

    for (int i = 0; i < FFT_SIZE * 2; i += 2) {

      int16_t left  = playBuffer[i];
      int16_t right = playBuffer[i+1];
      i2s_output.write16(left, right);

    }

    if (readyToSwap) {

      volatile int16_t* temp = playBuffer;
      playBuffer = fillBuffer;
      fillBuffer = temp;
      readyToSwap = false;

    }

  }

}

void setup1() {

  seed_random_safe();

}

void loop1() {

  static float time = 0;
  time += 0.001f;

  memset(vRealL, 0, sizeof(vRealL)); memset(vImagL, 0, sizeof(vImagL));
  memset(vRealR, 0, sizeof(vRealR)); memset(vImagR, 0, sizeof(vImagR));

  for (int i = 0; i < FFT_BINS; i++) {

    float pos = 30.0f + sinf(time * (0.2f + i * 0.05f)) * 29.5f;
    int binIdx = (int)pos;
    float angle = time * (1.0f + i * 0.3f);
    int32_t amp = (32768 + (int32_t)(sinf(time * 1.5f + i) * 32767));
    
    int32_t re = (int32_t)(amp * cosf(angle)) * AMP_SCALE;
    int32_t im = (int32_t)(amp * sinf(angle)) * AMP_SCALE;

    if (binIdx > 0 && binIdx < FFT_SIZE / 2) {

      if (i % 2 == 0) {
        vRealL[binIdx] += re;
        vImagL[binIdx] += im;
      } else {
        vRealR[binIdx] += re;
        vImagR[binIdx] += im;
      }
    }
  }

  fix32_fft(vRealL, vImagL, FFT_LOG2, 1);
  fix32_fft(vRealR, vImagR, FFT_LOG2, 1);

  for (int i = 0; i < FFT_SIZE; i++) {

    int32_t outL = vRealL[i] >> 16;
    int32_t outR = vRealR[i] >> 16;

    fillBuffer[i * 2]     = (int16_t)outL;
    fillBuffer[i * 2 + 1] = (int16_t)outR;

  }

  readyToSwap = true; 
  while(readyToSwap) { delay(1); }

}