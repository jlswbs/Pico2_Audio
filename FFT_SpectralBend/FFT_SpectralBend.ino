// IFFT float spectral databend recurrent field //

#include "hardware/structs/rosc.h"
#include <I2S.h>
#include "fft.h"

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define SAMPLE_RATE   44100

I2S i2s_output(OUTPUT);

#define LOG2_N 10
#define N (1 << LOG2_N)
#define I2S_WORDS N
#define HALF (N / 2)

#define N_PACKETS 8

#define LSTM_DECAY      0.85f
#define LSTM_INPUT      0.25f
#define LSTM_COUPLE     0.15f
#define LSTM_FREQ_STEP  3

struct Packet {
    int   start_bin;
    int   len;
    float amp;
    float phase;
    bool  on;
};

static Packet packets[N_PACKETS];

static void randomize_packet(Packet &p);

static float   real_f[N];
static float   imag_f[N];
static int16_t audio_buffer[N];
static int     sample_index = N;

static float   src_real[N];
static float   src_imag[N];

static float   lstm_real[HALF];
static float   lstm_imag[HALF];
static float   lstm_gate[HALF];
static bool    lstm_init = false;

static uint32_t rng_state = 0xDEAD10CCu;
static inline uint32_t rng_next() {
    uint32_t x = rng_state;
    x ^= x << 13; x ^= x >> 17; x ^= x << 5;
    rng_state = x;
    return x;
}

static inline float rng_uniform() {
    return (rng_next() >> 8) * (1.0f / 16777216.0f);
}

static inline int rng_range(int lo, int hi) {
    return lo + (int)(rng_next() % (uint32_t)(hi - lo + 1));
}

static uint32_t packet_tick_ms   = 40;
static uint32_t next_packet_tick = 0;
static uint32_t last_packet_tick = 0;
static int  hold_counter  = 0;
static int  hold_length   = 1;
static int16_t hold_sample = 0;
static int crush_shift = 0;

static int16_t last_packet_buffer[N];
static bool    have_last_packet = false;

static inline int16_t crush_sample(int16_t s) {
    if (crush_shift <= 0) return s;
    int32_t v = s;
    v >>= crush_shift;
    v <<= crush_shift;
    return (int16_t)v;
}

static void randomize_packet(Packet &p) {

    p.len       = rng_range(1, 4);
    p.start_bin = rng_range(2, HALF - 2 - p.len);
    p.amp       = 0.4f + rng_uniform() * 0.6f;
    p.phase     = rng_uniform() * 2.0f * (float)M_PI;
    p.on        = (rng_next() & 0x3) != 0;

}

static void lstm_step() {

    if (!lstm_init) {
        for (int b = 0; b < HALF; b++) {
            lstm_real[b] = 0.0f;
            lstm_imag[b] = 0.0f;
            lstm_gate[b] = 0.0f;
        }
        lstm_init = true;
    }

    static float next_real[HALF];
    static float next_imag[HALF];

    for (int b = 1; b < HALF - 1; b++) {
        float sr = lstm_real[b] * LSTM_DECAY;
        float si = lstm_imag[b] * LSTM_DECAY;

        sr += src_real[b] * LSTM_INPUT;
        si += src_imag[b] * LSTM_INPUT;

        float cr = 0.0f, ci = 0.0f;
        int n = 0;
        for (int k = -LSTM_FREQ_STEP; k <= LSTM_FREQ_STEP; k += LSTM_FREQ_STEP) {
            if (k == 0) continue;
            int nb = b + k;
            if (nb < 1 || nb >= HALF) continue;
            cr += lstm_real[nb];
            ci += lstm_imag[nb];
            n++;
        }
        if (n > 0) {
            sr += (cr / (float)n) * LSTM_COUPLE;
            si += (ci / (float)n) * LSTM_COUPLE;
        }

        sr = sr / (1.0f + fabsf(sr));
        si = si / (1.0f + fabsf(si));

        next_real[b] = sr;
        next_imag[b] = si;

        float mag = sqrtf(sr*sr + si*si);
        lstm_gate[b] = mag;
    }

    for (int b = 1; b < HALF - 1; b++) {
        lstm_real[b] = next_real[b];
        lstm_imag[b] = next_imag[b];
    }

    lstm_real[0] = 0.0f; lstm_imag[0] = 0.0f;
    lstm_real[HALF-1] = 0.0f; lstm_imag[HALF-1] = 0.0f;
    
}

static void new_data_tick(uint32_t now) {

    for (int i = 0; i < N_PACKETS; i++) {
        randomize_packet(packets[i]);
    }

    if ((rng_next() & 0x7) == 0) {
        int kill = rng_range(2, N_PACKETS);
        for (int k = 0; k < kill; k++) {
            packets[rng_range(0, N_PACKETS - 1)].on = false;
        }
    }

    int base = 15 + (int)(rng_next() % 60);
    if ((rng_next() & 0xF) == 0) base *= 2;
    packet_tick_ms   = base;
    next_packet_tick = now + packet_tick_ms;

    if ((rng_next() & 0x7) == 0) {
        hold_length = rng_range(2, 8);
    } else {
        hold_length = 1;
    }

    if ((rng_next() & 0xF) == 0) {
        crush_shift = rng_range(2, 10);
    } else {
        crush_shift = 0;
    }

}

static void build_spectrum_from_packets() {

    for (int i = 0; i < N; i++) {
        src_real[i] = 0.0f;
        src_imag[i] = 0.0f;
    }

    for (int p = 0; p < N_PACKETS; p++) {
        Packet &pk = packets[p];
        if (!pk.on) continue;

        int b_lo = pk.start_bin;
        int b_hi = pk.start_bin + pk.len - 1;
        if (b_lo < 1)    b_lo = 1;
        if (b_hi >= HALF) b_hi = HALF - 1;

        float cr = pk.amp * cosf(pk.phase);
        float ci = pk.amp * sinf(pk.phase);

        for (int b = b_lo; b <= b_hi; b++) {
            src_real[b] += cr;
            src_imag[b] += ci;
        }
    }

    lstm_step();

    for (int b = 1; b < HALF - 1; b++) {
        src_real[b] = lstm_real[b];
        src_imag[b] = lstm_imag[b];
    }
    src_real[0] = 0.0f;   src_imag[0] = 0.0f;
    src_real[HALF-1] = 0.0f; src_imag[HALF-1] = 0.0f;

    for (int b = 1; b < HALF; b++) {
        src_real[N - b] =  src_real[b];
        src_imag[N - b] = -src_imag[b];
    }

}

static void generate_field(uint32_t now) {

    build_spectrum_from_packets();

    for (int i = 0; i < N; i++) {
        real_f[i] = src_real[i];
        imag_f[i] = src_imag[i];
    }

    if ((rng_next() & 0x7) == 0) {
        for (int b = 1; b < HALF; b++) {
            if (lstm_gate[b] < 0.05f) {
                real_f[b] = 0.0f;
                imag_f[b] = 0.0f;
            }
        }
        for (int b = 1; b < HALF; b++) {
            real_f[N - b] =  real_f[b];
            imag_f[N - b] = -imag_f[b];
        }
    }

    fft(real_f, imag_f, N, 1);

    float peak = 0.0f;
    for (int i = 0; i < N; i++) {
        float v = fabsf(real_f[i]);
        if (v > peak) peak = v;
    }
    float norm = (peak > 0.001f) ? (1.0f / peak) : 1.0f;
    if (norm > 20.0f) norm = 20.0f;

    const float gain = 32767.0f * 0.5f * norm;
    bool repeat_packet = (rng_next() & 0x1F) == 0 && have_last_packet;

    for (int i = 0; i < N; i++) {
        int16_t s;
        if (repeat_packet) {
            s = last_packet_buffer[i];
        } else {
            float v = real_f[i] * gain;
            if (v >  32767.0f) v =  32767.0f;
            if (v < -32768.0f) v = -32768.0f;
            s = (int16_t)v;
        }
        audio_buffer[i] = s;
    }

    for (int i = 0; i < N; i++) last_packet_buffer[i] = audio_buffer[i];
    have_last_packet = true;

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
    rng_state = rand();

    i2s_output.setFrequency(SAMPLE_RATE);
    i2s_output.setDATA(I2S_DATA_PIN);
    i2s_output.setBCLK(I2S_BCLK_PIN);
    i2s_output.setBitsPerSample(16);
    i2s_output.setBuffers(I2S_BUFFERS, I2S_WORDS);
    i2s_output.begin();

    for (int i = 0; i < N_PACKETS; i++) {
        packets[i].on = false;
        randomize_packet(packets[i]);
    }
    build_spectrum_from_packets();

    uint32_t now = millis();
    last_packet_tick = now;
    new_data_tick(now);

}

void loop() {

    uint32_t now = millis();

    if (sample_index >= N) {
        generate_field(now);
        sample_index = 0;
    }

    int16_t s = audio_buffer[sample_index];

    if (hold_length > 1) {
        if (hold_counter <= 0) {
            hold_sample  = s;
            hold_counter = hold_length;
        }
        s = hold_sample;
        hold_counter--;
    }

    s = crush_sample(s);

    while (!i2s_output.write16(s, s)) {}
    sample_index++;

}

void setup1() {
    
    seed_random_safe();
    rng_state = rand();
    
}

void loop1() {

    uint32_t now = millis();

    if (now >= next_packet_tick) {
        last_packet_tick = now;
        new_data_tick(now);
    }

}