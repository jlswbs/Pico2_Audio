// IFFT float spectral steel drum engine //

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

#define MAX_VOICES 6

unsigned long last_trig  = 0;
const unsigned long trig_interval  = 250;
unsigned long last_decay = 0;
const unsigned long decay_interval = 1;

static float   real_f[N];
static float   imag_f[N];
static int16_t audio_buffer[N];
int sample_index = N;

const float pentatonic_ratios[] = {
    1.000f, 1.125f, 1.250f, 1.500f, 1.667f,
    2.000f, 2.250f, 2.500f, 3.000f, 3.333f
};
const int num_notes = sizeof(pentatonic_ratios) / sizeof(pentatonic_ratios[0]);

const float harmonics[] = {
    1.0f, 2.0f, 2.4f, 3.0f, 4.0f, 5.0f, 6.0f, 8.0f
};
const float harmonic_gains[] = {
    1.0f, 0.55f, 0.35f, 0.30f, 0.22f, 0.15f, 0.12f, 0.08f
};
const int num_harmonics = sizeof(harmonics) / sizeof(harmonics[0]);

struct Voice {
    float    base_freq;
    float    amplitude;
    float    phase[N / 2];
    bool     active;
    float    brightness;
};

Voice voices[MAX_VOICES];

static inline int freq_to_bin(float f) {
    int b = (int)(f * (float)N / (float)SAMPLE_RATE);
    if (b < 1) b = 1;
    if (b >= N / 2) b = N / 2 - 1;
    return b;
}

void trigger_steel_drum(float base_freq, float velocity) {
    int slot = -1;
    float lowest_amp = 1e9f;
    for (int i = 0; i < MAX_VOICES; i++) {
        if (!voices[i].active) { slot = i; break; }
        if (voices[i].amplitude < lowest_amp) {
            lowest_amp = voices[i].amplitude;
            slot = i;
        }
    }
    if (slot < 0) return;

    Voice &v = voices[slot];
    v.base_freq   = base_freq;
    v.amplitude   = velocity;
    v.brightness  = 0.4f + 0.6f * velocity;
    v.active      = true;
    for (int i = 0; i < N / 2; i++) v.phase[i] = 0.0f;
}

void generate_steel_drum() {

    for (int i = 0; i < N; i++) {
        real_f[i] = 0.0f;
        imag_f[i] = 0.0f;
    }

    for (int vi = 0; vi < MAX_VOICES; vi++) {
        Voice &v = voices[vi];
        if (!v.active || v.amplitude < 0.0005f) {
            v.active = false;
            continue;
        }

        for (int h = 0; h < num_harmonics; h++) {
            float freq = v.base_freq * harmonics[h];
            if (freq >= (float)SAMPLE_RATE * 0.45f) continue;

            int bin = freq_to_bin(freq);
            float amp = v.amplitude * harmonic_gains[h] * v.brightness;

            float detune = 1.0f + 0.03f * sinf((float)millis() * 0.007f + (float)h);
            int bin_d = freq_to_bin(freq * detune);
            if (bin_d >= 1 && bin_d < N / 2) bin = bin_d;

            if (bin > 0 && bin < N / 2) {
                v.phase[bin] += (2.0f * (float)M_PI * (float)bin);
                if (v.phase[bin] > 2.0f * (float)M_PI)
                    v.phase[bin] = fmodf(v.phase[bin], 2.0f * (float)M_PI);

                float c = cosf(v.phase[bin]);
                float s = sinf(v.phase[bin]);

                real_f[bin] += amp * c;
                imag_f[bin] += amp * s;
            }
        }
    }

    for (int i = 1; i < N / 2; i++) {
        real_f[N - i] =  real_f[i];
        imag_f[N - i] = -imag_f[i];
    }
    real_f[0] = 0.0f; imag_f[0] = 0.0f;
    real_f[N/2] = 0.0f; imag_f[N/2] = 0.0f;

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

    for (int i = 0; i < MAX_VOICES; i++) {
        voices[i].active = false;
        voices[i].amplitude = 0.0f;
        for (int j = 0; j < N / 2; j++) voices[i].phase[j] = 0.0f;
    }

    i2s_output.setFrequency(SAMPLE_RATE);
    i2s_output.setDATA(I2S_DATA_PIN);
    i2s_output.setBCLK(I2S_BCLK_PIN);
    i2s_output.setBitsPerSample(16);
    i2s_output.setBuffers(I2S_BUFFERS, I2S_WORDS);
    i2s_output.begin();

}

void loop() {

    if (sample_index >= N) {
        generate_steel_drum();
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
        int idx = random(0, num_notes);
        float base = 220.0f * pentatonic_ratios[idx];
        if (random(0, 100) < 30) base *= 2.0f;
        float velocity = 0.4f + (random(0, 1000) / 1000.0f) * 0.6f;
        trigger_steel_drum(base, velocity);

    }

    if (now - last_decay >= decay_interval) {

        last_decay = now;
        for (int i = 0; i < MAX_VOICES; i++) {
            Voice &v = voices[i];
            if (!v.active) continue;
            float rate = 0.00025f * (1.0f + v.base_freq / 400.0f);
            v.amplitude -= rate;
            if (v.amplitude <= 0.0f) {
                v.amplitude = 0.0f;
                v.active = false;
            }
        }
    }

}