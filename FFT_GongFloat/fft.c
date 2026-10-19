#include "fft.h"

/* Twiddles: cos/sin of 2*pi*k/FFT_MAX for k < FFT_MAX/2, from dsp_sin1 (which
 * is sin(2*pi*x), x in [0,1)). cos(2*pi*t) = sin(2*pi*(t + 0.25)). */
static float tw_cos[FFT_MAX / 2];
static float tw_sin[FFT_MAX / 2];

void fft_init(void)
{
    static int built;
    if (built) return;
    built = 1;
    for (int k = 0; k < FFT_MAX / 2; k++) {
        float x = (float)k * (1.0f / FFT_MAX);
        tw_cos[k] = dsp_sin1(x + 0.25f);
        tw_sin[k] = dsp_sin1(x);
    }
}

void fft(float *re, float *im, int n, int inverse)
{
    /* bit-reversal permutation */
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) {
            float t = re[i]; re[i] = re[j]; re[j] = t;
            t = im[i]; im[i] = im[j]; im[j] = t;
        }
    }
    /* butterflies: stage length 2, 4, ..., n */
    for (int len = 2; len <= n; len <<= 1) {
        int half = len >> 1;
        int tstep = FFT_MAX / len;              /* twiddle index step */
        for (int i = 0; i < n; i += len) {
            for (int k = 0; k < half; k++) {
                int ti = k * tstep;
                float wr = tw_cos[ti];
                float wi = inverse ? tw_sin[ti] : -tw_sin[ti];
                int a = i + k, b = a + half;
                float xr = re[b] * wr - im[b] * wi;
                float xi = re[b] * wi + im[b] * wr;
                re[b] = re[a] - xr;
                im[b] = im[a] - xi;
                re[a] += xr;
                im[a] += xi;
            }
        }
    }
    if (inverse) {
        float inv = 1.0f / (float)n;
        for (int i = 0; i < n; i++) { re[i] *= inv; im[i] *= inv; }
    }
}
