// IFFT float spectral frozen crystals //

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
#define MAX_SHARDS 20

#define REV_NUM_COMBS   4
#define REV_NUM_ALLPASS 2
#define REV_FEEDBACK    0.68f
#define REV_DAMP        0.02f
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
        rev_comb_len[i]    = comb_tuning[i] % 4096;
        rev_comb_idx[i]    = 0;
        rev_comb_filter[i] = 0.0f;
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

struct IceShard {
    float center;
    float width;
    float amp;
    float phase;
    float growth;
    float facet;
    float thaw_time;
    float frozen_for;
    uint32_t id;
    bool alive;
    bool frozen;
};

static IceShard shards[MAX_SHARDS];
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

static inline float rng_uniform() {

    return (rng_next() >> 8) * (1.0f / 16777216.0f);

}

static bool freeze_shard(float center, float width, float amp, uint32_t now) {

    int slot = -1;
    for (int i = 0; i < MAX_SHARDS; i++) {
        if (!shards[i].alive) { slot = i; break; }
    }
    if (slot < 0) return false;

    if (center < 2.0f)      center = 2.0f;
    if (center > N * 0.45f) center = N * 0.45f;
    if (width  < 0.5f)      width  = 0.5f;
    if (width  > 4.0f)      width  = 4.0f;
    if (amp    < 0.001f)    return false;
    if (amp    > 1.0f)      amp    = 1.0f;

    IceShard &s = shards[slot];
    s.center     = center;
    s.width      = width;
    s.amp        = amp;
    s.phase      = rng_uniform() * 2.0f * (float)M_PI;
    s.growth     = 0.05f + rng_uniform() * 0.3f;
    s.facet      = 0.3f + rng_uniform() * 0.7f;
    s.thaw_time  = 4.0f + rng_uniform() * 20.0f;
    s.frozen_for = 0.0f;
    s.id         = next_id++;
    s.alive      = true;
    s.frozen     = false;
    return true;

}

void frost_growth(float dt_s) {

    for (int i = 0; i < MAX_SHARDS; i++) {
        IceShard &s = shards[i];
        if (!s.alive) continue;

        s.frozen_for += dt_s;

        if (!s.frozen) {
            s.amp += s.growth * dt_s * (1.0f - s.amp);
            if (s.amp > 0.95f) { s.amp = 0.95f; s.frozen = true; }
            s.width *= (1.0f - 0.05f * dt_s);
            if (s.width < 0.4f) s.width = 0.4f;
        }

        if (s.frozen_for > s.thaw_time) {
            s.amp -= 2.0f * dt_s;
            if (s.amp <= 0.0f) { s.alive = false; s.amp = 0.0f; }
        }
    }

}

void shatter_twins(uint32_t now) {

    for (int i = 0; i < MAX_SHARDS; i++) {
        if (!shards[i].alive) continue;
        for (int j = i + 1; j < MAX_SHARDS; j++) {
            if (!shards[j].alive) continue;

            float d = fabsf(shards[i].center - shards[j].center);
            if (d < 0.5f && shards[i].frozen && shards[j].frozen) {
                float mid = (shards[i].center + shards[j].center) * 0.5f;
                float new_amp = sqrtf(shards[i].amp * shards[j].amp) * 0.5f;
                if (freeze_shard(mid, 0.6f, new_amp, now)) {
                    shards[i].amp *= 0.85f;
                    shards[j].amp *= 0.85f;
                }
            }
        }
    }

}

void cold_snap(uint32_t now) {

    if ((rng_next() & 0xFFFF) < 12) {
        float center = 3.0f + rng_uniform() * (N * 0.42f);
        float width  = 0.8f + rng_uniform() * 1.5f;
        float amp    = 0.01f + rng_uniform() * 0.03f;
        freeze_shard(center, width, amp, now);
    }

}

void generate_field() {

    for (int i = 0; i < N; i++) { real_f[i] = 0.0f; imag_f[i] = 0.0f; }

    float total_amp = 0.0f;

    for (int k = 0; k < MAX_SHARDS; k++) {
        IceShard &s = shards[k];
        if (!s.alive || s.amp < 0.001f) continue;
        total_amp += s.amp;

        int b_lo = (int)(s.center - s.width);
        int b_hi = (int)(s.center + s.width);
        if (b_lo < 1)       b_lo = 1;
        if (b_hi > N/2 - 1) b_hi = N/2 - 1;

        for (int b = b_lo; b <= b_hi; b++) {
            float x = (b - s.center) / s.width;
            float edge = cosf(0.5f * (float)M_PI * dsp_clamp(x, -1.0f, 1.0f));
            edge = powf(fabsf(edge), 1.0f + 3.0f * (1.0f - s.facet));
            float a = s.amp * edge;

            real_f[b] += a * cosf(s.phase);
            imag_f[b] += a * sinf(s.phase);
        }

        if (s.frozen) {
            int h3 = (int)(s.center * 3.0f);
            int h5 = (int)(s.center * 5.0f);
            if (h3 > 1 && h3 < N/2 - 1) {
                float a = s.amp * 0.22f * s.facet;
                real_f[h3] += a * cosf(s.phase * 3.0f);
                imag_f[h3] += a * sinf(s.phase * 3.0f);
            }
            if (h5 > 1 && h5 < N/2 - 1) {
                float a = s.amp * 0.14f * s.facet;
                real_f[h5] += a * cosf(s.phase * 5.0f);
                imag_f[h5] += a * sinf(s.phase * 5.0f);
            }
        }
    }

    if ((rng_next() & 0x3FF) < 3) {
        int crack_bin = 4 + (rng_next() % (N/2 - 8));
        float crack_amp = 0.05f + rng_uniform() * 0.1f;
        real_f[crack_bin] += crack_amp * cosf(rng_uniform() * 6.283f);
        imag_f[crack_bin] += crack_amp * sinf(rng_uniform() * 6.283f);
    }

    for (int b = 1; b < N / 2; b++) {
        real_f[N - b] =  real_f[b];
        imag_f[N - b] = -imag_f[b];
    }
    real_f[0] = 0.0f;   imag_f[0] = 0.0f;
    real_f[N/2] = 0.0f; imag_f[N/2] = 0.0f;

    fft(real_f, imag_f, N, 1);

    float norm = 1.0f;
    if (total_amp > 0.01f) norm = 1.0f / sqrtf(total_amp);
    if (norm > 10.0f) norm = 10.0f;
    if (norm < 0.1f)  norm = 0.1f;

    const float gain = 32767.0f * 3.0f * norm;
    for (int i = 0; i < N; i++) {
        float v = real_f[i] * gain / 32767.0f;
        v = dsp_hard(v) * 32767.0f;
        audio_buffer[i] = (int16_t)v;
    }

    float chill = 0.005f;
    for (int i = 0; i < N; i++) {
        audio_buffer[i] += (int16_t)((rng_next() & 0xFF) - 128) * chill;
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

    float base = N * 0.04f;
    freeze_shard(base,        1.0f, 0.10f, millis());
    freeze_shard(base * 1.5f, 0.8f, 0.06f, millis());
    freeze_shard(base * 2.0f, 0.6f, 0.04f, millis());

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
    uint32_t now = millis();
    float dt_s = (now - last_ms) * 0.2f;
    last_ms = now;
    if (dt_s > 0.1f) dt_s = 0.1f;

    frost_growth(dt_s);
    shatter_twins(now);
    cold_snap(now);

}