// IFFT float spectral anorganic growth //

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
#define MAX_CRYSTALS 40

#define REV_NUM_COMBS   4
#define REV_NUM_ALLPASS 2
#define REV_FEEDBACK    0.72f
#define REV_DAMP        0.05f
#define REV_WET         0.45f
#define REV_DRY         0.55f

static int16_t rev_comb_buf[REV_NUM_COMBS][4096];
static int16_t rev_ap_buf[REV_NUM_ALLPASS][1024];
static int     rev_comb_idx[REV_NUM_COMBS];
static int     rev_ap_idx[REV_NUM_ALLPASS];
static float   rev_comb_filter[REV_NUM_COMBS];
static int     rev_comb_len[REV_NUM_COMBS];
static int     rev_ap_len[REV_NUM_ALLPASS];

static const int comb_tuning[REV_NUM_COMBS]     = { 1557, 1617, 1491, 1422 };
static const int allpass_tuning[REV_NUM_ALLPASS] = {  225,  341 };

void reverb_init() {

    for (int i = 0; i < REV_NUM_COMBS; i++) {
        rev_comb_len[i]   = comb_tuning[i] % 4096;
        rev_comb_idx[i]   = 0;
        rev_comb_filter[i]= 0.0f;
        memset(rev_comb_buf[i], 0, sizeof(rev_comb_buf[i]));
    }
    for (int i = 0; i < REV_NUM_ALLPASS; i++) {
        rev_ap_len[i] = allpass_tuning[i] % 1024;
        rev_ap_idx[i] = 0;
        memset(rev_ap_buf[i], 0, sizeof(rev_ap_buf[i]));
    }

}

static inline float reverb_process(float in) {

    float out = 0.0f;
    for (int i = 0; i < REV_NUM_COMBS; i++) {
        int idx = rev_comb_idx[i];
        int len = rev_comb_len[i];
        float delayed = rev_comb_buf[i][idx];

        rev_comb_filter[i] = delayed * (1.0f - REV_DAMP) + rev_comb_filter[i] * REV_DAMP;
        rev_comb_buf[i][idx] = (int16_t)(in + rev_comb_filter[i] * REV_FEEDBACK);
        rev_comb_idx[i] = (idx + 1) % len;
        out += delayed;
    }
    out *= (1.0f / REV_NUM_COMBS);

    for (int i = 0; i < REV_NUM_ALLPASS; i++) {
        int idx = rev_ap_idx[i];
        int len = rev_ap_len[i];
        float delayed = rev_ap_buf[i][idx];
        float feed = out + delayed * 0.5f;
        rev_ap_buf[i][idx] = (int16_t)feed;
        rev_ap_idx[i] = (idx + 1) % len;
        out = delayed - out;
    }
    return in * REV_DRY + out * REV_WET;

}

float dsp_clamp(float x, float lo, float hi) { return x < lo ? lo : x > hi ? hi : x; }

float dsp_hard(float x) {
    x = dsp_clamp(x, -1.0f, 1.0f);
    return 1.5f * x - 0.5f * x * x * x;
}

struct Crystal {
    float center;
    float width;
    float amp;
    float phase;
    float growth;
    float facet;
    float lifetime;
    float age;
    uint32_t id;
    bool alive;
    bool saturated;
};

static Crystal crys[MAX_CRYSTALS];
static uint32_t next_id = 1;

static float   real_f[N];
static float   imag_f[N];
static int16_t audio_buffer[N];
int sample_index = N;

static uint32_t rng_state = 0xC0FFEE11u;
static inline uint32_t rng_next() {

    uint32_t x = rng_state;
    x ^= x << 13; x ^= x >> 17; x ^= x << 5;
    rng_state = x;
    return x;

}

static inline float rng_uniform() { return (rng_next() >> 8) * (1.0f / 16777216.0f); }

static bool nucleate(float center, float width, float amp, uint32_t now) {

    int slot = -1;
    for (int i = 0; i < MAX_CRYSTALS; i++) if (!crys[i].alive) { slot = i; break; }
    if (slot < 0) return false;

    if (center < 2.0f)       center = 2.0f;
    if (center > N * 0.45f)  center = N * 0.45f;
    if (width  < 0.5f)       width  = 0.5f;
    if (width  > 4.0f)       width  = 4.0f;
    if (amp    < 0.001f)     return false;
    if (amp    > 1.0f)       amp    = 1.0f;

    Crystal &c = crys[slot];
    c.center    = center;
    c.width     = width;
    c.amp       = amp;
    c.phase     = rng_uniform() * 2.0f * (float)M_PI;
    c.growth    = 0.05f + rng_uniform() * 0.3f;
    c.facet     = 0.3f + rng_uniform() * 0.7f;
    c.lifetime  = 4.0f + rng_uniform() * 20.0f;
    c.age       = 0.0f;
    c.id        = next_id++;
    c.alive     = true;
    c.saturated = false;
    return true;

}

void grow_crystals(float dt_s) {

    for (int i = 0; i < MAX_CRYSTALS; i++) {
        Crystal &c = crys[i];
        if (!c.alive) continue;

        c.age += dt_s;

        if (!c.saturated) {
            c.amp += c.growth * dt_s * (1.0f - c.amp);
            if (c.amp > 0.95f) { c.amp = 0.95f; c.saturated = true; }
            c.width *= (1.0f - 0.05f * dt_s);
            if (c.width < 0.4f) c.width = 0.4f;
        }

        if (c.age > c.lifetime) {
            c.amp -= 2.0f * dt_s;
            if (c.amp <= 0.0f) { c.alive = false; c.amp = 0.0f; }
        }
    }

}

void twin_crystals(uint32_t now) {

    for (int i = 0; i < MAX_CRYSTALS; i++) {
        if (!crys[i].alive) continue;
        for (int j = i + 1; j < MAX_CRYSTALS; j++) {
            if (!crys[j].alive) continue;

            float d = fabsf(crys[i].center - crys[j].center);

            if (d < 0.5f && crys[i].saturated && crys[j].saturated) {
                float mid = (crys[i].center + crys[j].center) * 0.5f;
                float new_amp = sqrtf(crys[i].amp * crys[j].amp) * 0.5f;
                if (nucleate(mid, 0.6f, new_amp, now)) {
                    crys[i].amp *= 0.85f;
                    crys[j].amp *= 0.85f;
                }
            }
        }
    }

}

void spontaneous_nucleation(uint32_t now) {

    if ((rng_next() & 0xFFFF) < 12) {
        float center = 3.0f + rng_uniform() * (N * 0.42f);
        float width  = 0.8f + rng_uniform() * 1.5f;
        float amp    = 0.01f + rng_uniform() * 0.03f;
        nucleate(center, width, amp, now);
    }

}

void generate_field() {

    for (int i = 0; i < N; i++) { real_f[i] = 0.0f; imag_f[i] = 0.0f; }

    float total_amp = 0.0f;

    for (int k = 0; k < MAX_CRYSTALS; k++) {
        Crystal &c = crys[k];
        if (!c.alive || c.amp < 0.001f) continue;
        total_amp += c.amp;

        int b_lo = (int)(c.center - c.width);
        int b_hi = (int)(c.center + c.width);
        if (b_lo < 1) b_lo = 1;
        if (b_hi > N/2 - 1) b_hi = N/2 - 1;

        for (int b = b_lo; b <= b_hi; b++) {
            float x = (b - c.center) / c.width;
            float edge = cosf(0.5f * (float)M_PI * dsp_clamp(x, -1.0f, 1.0f));
            edge = powf(fabsf(edge), 1.0f + 3.0f * (1.0f - c.facet));
            float a = c.amp * edge;

            real_f[b] += a * cosf(c.phase);
            imag_f[b] += a * sinf(c.phase);
        }

        if (c.saturated) {
            int h3 = (int)(c.center * 3.0f);
            int h5 = (int)(c.center * 5.0f);
            if (h3 > 1 && h3 < N/2 - 1) {
                float a = c.amp * 0.15f * c.facet;
                real_f[h3] += a * cosf(c.phase * 3.0f);
                imag_f[h3] += a * sinf(c.phase * 3.0f);
            }
            if (h5 > 1 && h5 < N/2 - 1) {
                float a = c.amp * 0.08f * c.facet;
                real_f[h5] += a * cosf(c.phase * 5.0f);
                imag_f[h5] += a * sinf(c.phase * 5.0f);
            }
        }
    }

    for (int b = 1; b < N / 2; b++) {
        real_f[N - b] =  real_f[b];
        imag_f[N - b] = -imag_f[b];
    }

    real_f[0] = 0.0f; imag_f[0] = 0.0f;
    real_f[N/2] = 0.0f; imag_f[N/2] = 0.0f;

    fft(real_f, imag_f, N, 1);

    float norm = 1.0f;
    if (total_amp > 0.01f) norm = 1.0f / sqrtf(total_amp);
    if (norm > 10.0f) norm = 10.0f;
    if (norm < 0.1f)  norm = 0.1f;

    const float gain = 32767.0f * 6.0f * norm;
    for (int i = 0; i < N; i++) {
        float v = real_f[i] * gain / 32767.0f;
        v = dsp_hard(v) * 32767.0f;
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
    reverb_init();
    rng_state = rand();

    i2s_output.setFrequency(SAMPLE_RATE);
    i2s_output.setDATA(I2S_DATA_PIN);
    i2s_output.setBCLK(I2S_BCLK_PIN);
    i2s_output.setBitsPerSample(16);
    i2s_output.setBuffers(I2S_BUFFERS, I2S_WORDS);
    i2s_output.begin();

    for (int i = 0; i < 8; i++) {
        float c = 3.0f + rng_uniform() * (N * 0.42f);
        float w = 0.6f + rng_uniform() * 1.2f;
        float a = 0.02f + rng_uniform() * 0.05f;
        nucleate(c, w, a, 0);
    }

}

void loop() {

    if (sample_index >= N) {
        generate_field();
        sample_index = 0;
    }
    int16_t dry = audio_buffer[sample_index];
    int16_t wet = (int16_t)reverb_process((float)dry);
    while (!i2s_output.write16(wet, wet)) {}
    sample_index++;

}

void setup1() { 
    
    seed_random_safe();
    rng_state = rand();
    
}

void loop1() {

    static uint32_t last_ms = 0;
    uint32_t now = micros();
    float dt_s = (now - last_ms) * 0.0002f;
    last_ms = now;
    if (dt_s > 0.1f) dt_s = 0.1f;

    grow_crystals(dt_s);
    twin_crystals(now);
    spontaneous_nucleation(now);

}