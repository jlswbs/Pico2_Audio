// IFFT float spectral organic growth //

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
#define MAX_ORGS 24

#define REV_NUM_COMBS   8
#define REV_NUM_ALLPASS 4
#define REV_ROOMSIZE    0.84f
#define REV_DAMP        0.30f
#define REV_WET         0.35f
#define REV_DRY         0.75f

static int16_t rev_comb_buf[REV_NUM_COMBS][2048];
static int16_t rev_ap_buf[REV_NUM_ALLPASS][512];
static int     rev_comb_idx[REV_NUM_COMBS];
static int     rev_ap_idx[REV_NUM_ALLPASS];
static float   rev_comb_filter[REV_NUM_COMBS];
static int     rev_comb_len[REV_NUM_COMBS];
static int     rev_ap_len[REV_NUM_ALLPASS];

static const int comb_tuning[REV_NUM_COMBS]    = {1116, 1188, 1277, 1356, 1422, 1491, 1557, 1617};
static const int allpass_tuning[REV_NUM_ALLPASS] = { 556,  441,  341,  225};

void reverb_init() {

    for (int i = 0; i < REV_NUM_COMBS; i++) {
        rev_comb_len[i]   = comb_tuning[i] % 2048;
        rev_comb_idx[i]   = 0;
        rev_comb_filter[i]= 0.0f;
        memset(rev_comb_buf[i], 0, sizeof(rev_comb_buf[i]));
    }
    for (int i = 0; i < REV_NUM_ALLPASS; i++) {
        rev_ap_len[i] = allpass_tuning[i] % 512;
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
        rev_comb_buf[i][idx] = (int16_t)(in + rev_comb_filter[i] * REV_ROOMSIZE);
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

float dsp_tanh(float x) {

  x = dsp_clamp(x, -3.0f, 3.0f);
  float x2 = x * x;
  return x * (27.0f + x2) / (27.0f + 9.0f * x2);

}

struct Organism {
    float center;
    float width;
    float skew;
    float amp;
    float phase;
    float birth;
    float lifespan;
    float drift;
    float breath;
    float breath_phase;
    float coupling_strength;
    float coupling_target;
    bool alive;
    uint32_t id;
};

static Organism orgs[MAX_ORGS];
static uint32_t next_id = 1;
static uint32_t global_time = 0;

static float   real_f[N];
static float   imag_f[N];
static int16_t audio_buffer[N];
int sample_index = N;

static uint32_t rng_state = 0x12345678u;

static inline uint32_t rng_next() {

    uint32_t x = rng_state;
    x ^= x << 13; x ^= x >> 17; x ^= x << 5;
    rng_state = x;
    return x;

}

static inline float rng_uniform() {
    return (rng_next() >> 8) * (1.0f / 16777216.0f);
}

static float rng_gauss() {

    float u1 = rng_uniform() + 1e-7f;
    float u2 = rng_uniform();
    return sqrtf(-2.0f * logf(u1)) * cosf(2.0f * (float)M_PI * u2);

}

void evolve_organisms(uint32_t now_ms) {

    for (int i = 0; i < MAX_ORGS; i++) {
        Organism &o = orgs[i];
        if (!o.alive) continue;

        float age_ms = (float)(now_ms - o.birth);
        float local_dt = age_ms / o.lifespan;
        if (local_dt < 0.0f) local_dt = 0.0f;

        float age_s = age_ms * 0.001f;

        float breath_phase = o.breath_phase + 2.0f * (float)M_PI * o.breath * age_s;
        float breath_mod = sinf(breath_phase);
        o.amp *= (1.0f + 0.1f * breath_mod);
        if (o.amp > 1.0f) o.amp = 1.0f;
        if (o.amp < 0.0f) o.amp = 0.0f;

        o.center += o.drift * (1.0f + 0.5f * sinf(breath_phase * 0.3f));
        if (o.center < 1.0f)       o.center = 1.0f;
        if (o.center > N * 0.45f)  o.center = N * 0.45f;

        o.width *= 1.00002f;
        if (o.width > 8.0f) o.width = 8.0f;

        if (local_dt > 1.0f || o.amp < 0.003f) {
            o.alive = false;
            continue;
        }

        float life_fade = 1.0f - local_dt * local_dt;
        o.amp -= 0.002f * (1.0f - life_fade);
        if (o.amp < 0.0f) o.amp = 0.0f;
    }

}

void interact_organisms() {

    for (int i = 0; i < MAX_ORGS; i++) {
        if (!orgs[i].alive) continue;
        for (int j = i + 1; j < MAX_ORGS; j++) {
            if (!orgs[j].alive) continue;

            float d_center = fabsf(orgs[i].center - orgs[j].center);
            float overlap = expf(-d_center * d_center /
                                 (2.0f * (orgs[i].width + orgs[j].width)));

            if (overlap < 0.1f) continue;

            float exchange = 0.001f * overlap *
                             orgs[i].coupling_strength *
                             orgs[j].coupling_strength;

            float coh_i = 1.0f / (1.0f + orgs[i].width);
            float coh_j = 1.0f / (1.0f + orgs[j].width);
            float coherence = coh_i * coh_j;

            if (coherence > 0.5f) {
                float room_i = 1.0f - orgs[i].amp;
                float room_j = 1.0f - orgs[j].amp;
                if (room_i < 0.0f) room_i = 0.0f;
                if (room_j < 0.0f) room_j = 0.0f;
                orgs[i].amp += exchange * orgs[j].amp * room_i;
                orgs[j].amp += exchange * orgs[i].amp * room_j;
            } else {
                if (orgs[i].amp < orgs[j].amp) {
                    orgs[i].amp -= exchange * orgs[j].amp;
                    if (orgs[i].amp < 0.0f) orgs[i].amp = 0.0f;
                } else {
                    orgs[j].amp -= exchange * orgs[i].amp;
                    if (orgs[j].amp < 0.0f) orgs[j].amp = 0.0f;
                }
            }

            float phase_diff = orgs[i].phase - orgs[j].phase;
            orgs[i].phase -= 0.002f * overlap * sinf(phase_diff);
            orgs[j].phase += 0.002f * overlap * sinf(phase_diff);
        }
    }

}

void submerge_emerge() {

    for (int i = 0; i < MAX_ORGS; i++) {
        if (!orgs[i].alive) continue;
        for (int j = 0; j < MAX_ORGS; j++) {
            if (i == j || !orgs[j].alive) continue;

            float d = fabsf(orgs[i].center - orgs[j].center);
            if (d < orgs[j].width * 0.5f && orgs[i].width < orgs[j].width * 0.5f) {
                orgs[j].amp += orgs[i].amp * 0.5f;
                orgs[i].amp *= 0.7f;
                orgs[j].width = fmaxf(orgs[j].width, orgs[i].width * 1.2f);
            }
        }
    }

}

static bool spawn_organism(float center, float width, float amp, uint32_t now) {

    int slot = -1;
    for (int i = 0; i < MAX_ORGS; i++) {
        if (!orgs[i].alive) { slot = i; break; }
    }
    if (slot < 0) return false;

    if (center < 1.0f)          center = 1.0f;
    if (center > N * 0.45f)     center = N * 0.45f;
    if (width  < 0.3f)          width  = 0.3f;
    if (width  > 8.0f)          width  = 8.0f;
    if (amp    < 0.001f)        return false;
    if (amp    > 1.0f)          amp    = 1.0f;

    Organism &o = orgs[slot];
    o.center   = center;
    o.width    = width;
    o.skew     = (rng_uniform() - 0.5f) * 0.8f;
    o.amp      = amp;
    o.phase    = rng_uniform() * 2.0f * (float)M_PI;
    o.birth    = now;
    o.lifespan = 3000.0f + rng_uniform() * 12000.0f;
    o.drift    = (rng_uniform() - 0.5f) * 0.002f;
    o.breath   = 0.5f + rng_uniform() * 2.0f;
    o.breath_phase = rng_uniform() * 2.0f * (float)M_PI;
    o.coupling_strength = 0.05f + rng_uniform() * 0.2f;
    o.coupling_target   = -1;
    o.alive    = true;
    o.id       = next_id++;
    return true;

}

static void compact_organisms() {

    float dead_energy = 0.0f;

    for (int i = 0; i < MAX_ORGS; i++) {
        if (!orgs[i].alive && orgs[i].amp > 0.0f) {
            dead_energy += orgs[i].amp;
        }
    }

    int write = 0;
    for (int i = 0; i < MAX_ORGS; i++) {
        if (orgs[i].alive) {
            if (write != i) orgs[write] = orgs[i];
            write++;
        }
    }
    for (int i = write; i < MAX_ORGS; i++) {
        orgs[i].alive = false;
        orgs[i].amp   = 0.0f;
    }

    if (dead_energy > 0.05f && (rng_next() & 0xFF) < 64) {
        float center = 1.0f + rng_uniform() * (N * 0.45f);
        float width  = 3.0f + rng_uniform() * 4.0f;
        float amp    = fminf(0.1f, dead_energy * 0.3f);
        spawn_organism(center, width, amp, millis());
    }

}

void spawn_from_emergence(uint32_t now) {

    for (int i = 0; i < MAX_ORGS; i++) {
        if (!orgs[i].alive) continue;
        for (int j = i + 1; j < MAX_ORGS; j++) {
            if (!orgs[j].alive) continue;
            float d = fabsf(orgs[i].center - orgs[j].center);
            float overlap = expf(-d * d /
                                 (2.0f * (orgs[i].width + orgs[j].width)));

            if (overlap > 0.7f && orgs[i].amp > 0.1f && orgs[j].amp > 0.1f) {
                float new_center = (orgs[i].center + orgs[j].center) * 0.5f;
                float new_amp = sqrtf(orgs[i].amp * orgs[j].amp) * 0.3f;

                if (spawn_organism(new_center, 0.5f, new_amp, now)) {
                    orgs[i].amp *= 0.9f;
                    orgs[j].amp *= 0.9f;
                }
            }
        }
    }

    if ((rng_next() & 0xFFFF) < 50) {
        float center = 1.0f + rng_uniform() * (N * 0.45f);
        float amp = 0.02f + rng_uniform() * 0.05f;
        spawn_organism(center, 1.0f + rng_uniform() * 3.0f, amp, now);
    }

}

void generate_field() {

    for (int i = 0; i < N; i++) { real_f[i] = 0.0f; imag_f[i] = 0.0f; }

    float total_amp = 0.0f;

    for (int i = 0; i < MAX_ORGS; i++) {
        Organism &o = orgs[i];
        if (!o.alive || o.amp < 0.001f) continue;
        total_amp += o.amp;

        for (int b = 1; b < N / 2; b++) {
            float x = ((float)b - o.center) / o.width;
            float skew_mod = 1.0f + o.skew * x;
            float env = expf(-0.5f * x * x) * skew_mod;
            if (env < 0.001f) continue;

            float phase = o.phase + (1.0f - 1.0f / (1.0f + o.width)) *
                          (rng_uniform() - 0.5f) * 2.0f;

            float a = o.amp * env;
            real_f[b] += a * cosf(phase);
            imag_f[b] += a * sinf(phase);
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
    if (total_amp > 0.01f) {
        norm = 1.0f / sqrtf(total_amp);
    }
    if (norm > 10.0f) norm = 10.0f;
    if (norm < 0.1f)  norm = 0.1f;

    const float gain = 32767.0f * 3.0f * norm;
    for (int i = 0; i < N; i++) {
        float v = real_f[i] * gain;
        v = 32767.0f * dsp_tanh(v / 32767.0f);
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

    for (int i = 0; i < 4; i++) {
        float c = 2.0f + rng_uniform() * (N * 0.4f);
        float w = 0.5f + rng_uniform() * 1.5f;
        float a = 0.05f + rng_uniform() * 0.1f;
        spawn_organism(c, w, a, millis());
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

    uint32_t now = millis();
    global_time = now;

    evolve_organisms(now);
    interact_organisms();
    submerge_emerge();
    spawn_from_emergence(now);
    compact_organisms();

}