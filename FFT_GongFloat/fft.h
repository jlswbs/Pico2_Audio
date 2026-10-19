/* Radix-2 float FFT, in-place, freestanding (no libm). Twiddles come from the
 * engine's dsp_sin1, so it obeys the same no-libm rule as the rest of src/.
 *
 * Scalar only for now: XTheadVector has no cheap lane permute/gather for the
 * butterflies, so unlike the osc/voice kernels there is no RVV twin yet (see
 * docs/ENGINE.md). It is the foundation for the partitioned IR convolution
 * (issue #4) and the spectral effects of issue #5. */
#ifndef FFT_H
#define FFT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define FFT_MAX 4096                      /* largest supported size, power of 2 */

/* sin(2 pi p) for any p (period 1): parabola plus one refinement step
 * (max abs error ~0.001). */
static inline float dsp_sin1(float p)
{
    float z = 2.0f * (p - (float)(int32_t)p);     /* (-2, 2) */
    if (z >= 1.0f) z -= 2.0f;
    else if (z < -1.0f) z += 2.0f;                /* [-1, 1): angle = z * pi */
    float az = z < 0.0f ? -z : z;
    float y = 4.0f * z * (1.0f - az);
    float ay = y < 0.0f ? -y : y;
    return y + 0.225f * (y * ay - y);
}

void fft_init(void);                      /* build the twiddle tables (once) */
/* In-place size-n FFT; n is a power of two, n <= FFT_MAX. inverse = 1 applies
 * the true inverse (it divides by n). re/im are length n. */
void fft(float *re, float *im, int n, int inverse);

#ifdef __cplusplus
}
#endif

#endif