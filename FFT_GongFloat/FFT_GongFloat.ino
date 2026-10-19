// IFFT float spectral gong engine //

#include "hardware/structs/rosc.h"
#include <I2S.h>
#include "fft.h"

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define SAMPLE_RATE   44100

I2S i2s_output(OUTPUT);

#define LOG2_N 8
#define N (1 << LOG2_N)
#define I2S_WORDS N

unsigned long last_trig  = 0;
const unsigned long trig_interval  = 2500;
unsigned long last_decay = 0;
const unsigned long decay_interval = 2;

static float   real_f[N];
static float   imag_f[N];
static int16_t audio_buffer[N];
int sample_index = N;

const float metal_frequencies[] = {0.018f, 0.035f, 0.058f, 0.072f, 0.095f, 0.125f, 0.168f, 0.205f, 0.255f, 0.310f};
const int num_bins = sizeof(metal_frequencies) / sizeof(metal_frequencies[0]);

volatile float bin_amplitudes[N / 2] = {0};
float phase_accumulator[N / 2] = {0};

void generate_spectral_gong() {

    for (int i = 0; i < N; i++) {
        real_f[i] = 0.0f;
        imag_f[i] = 0.0f;
    }

    for (int i = 0; i < num_bins; i++) {
        int bin = (int)(metal_frequencies[i] * (float)N);

        if (bin > 0 && bin < N / 2) {
            float amp = bin_amplitudes[bin];
            if (amp > 0.001f) {
                phase_accumulator[bin] += (2.0f * (float)M_PI * (float)bin);
                if (phase_accumulator[bin] > 2.0f * (float)M_PI)
                    phase_accumulator[bin] = fmodf(phase_accumulator[bin], 2.0f * (float)M_PI);

                float c = cosf(phase_accumulator[bin]);
                float s = sinf(phase_accumulator[bin]);

                real_f[bin] = amp * c;
                imag_f[bin] = amp * s;
                real_f[N - bin] =  real_f[bin];
                imag_f[N - bin] = -imag_f[bin];
            }
        }
    }

    fft(real_f, imag_f, N, 1);

    const float output_gain = 32767.0f;
    for (int i = 0; i < N; i++) {
        float v = real_f[i] * output_gain;
        if (v >  32767.0f) v =  32767.0f;
        if (v < -32768.0f) v = -32768.0f;
        audio_buffer[i] = (int16_t)v;
    }

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

    fft_init();

    i2s_output.setFrequency(SAMPLE_RATE);
    i2s_output.setDATA(I2S_DATA_PIN);
    i2s_output.setBCLK(I2S_BCLK_PIN);
    i2s_output.setBitsPerSample(16);
    i2s_output.setBuffers(I2S_BUFFERS, I2S_WORDS);
    i2s_output.begin();

}

void loop() {

    if (sample_index >= N) {
        generate_spectral_gong();
        sample_index = 0;
    }

    int16_t sample = audio_buffer[sample_index];

    while (!i2s_output.write16(sample, sample)) {}

    sample_index++;

}

void setup1() {

    seed_random_safe();

}

void loop1() {

    unsigned long now = millis();

    if (now - last_trig >= trig_interval) {
        last_trig = now;
        float strike_energy = 0.3f + (random(0, 1000) / 1000.0f) * 0.5f;

        for (int i = 0; i < num_bins; i++) {
            int bin = (int)(metal_frequencies[i] * (float)N);
            if (bin > 0 && bin < N / 2) {
                bin_amplitudes[bin] = strike_energy / (1.0f + i);
            }
        }
    }

    if (now - last_decay >= decay_interval) {
        last_decay = now;
        for (int bin = 0; bin < N / 2; bin++) {
            float a = bin_amplitudes[bin];
            if (a > 0.0f) {
                float decay_step = (1.0f + (bin / 2.0f)) / 10000.0f;
                a -= decay_step;
                bin_amplitudes[bin] = (a > 0.0f) ? a : 0.0f;
            }
        }
    }

}