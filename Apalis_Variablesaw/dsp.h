#pragma once
#ifndef DSY_CORE_DSP
#define DSY_CORE_DSP
#include <cassert>
#include <cstdint>
#include <random>
#include <cmath>

#define PI_F 3.1415927410125732421875f
#define TWOPI_F (2.0f * PI_F)
#define HALFPI_F (PI_F * 0.5f)
#define DSY_MIN(in, mn) (in < mn ? in : mn)
#define DSY_MAX(in, mx) (in > mx ? in : mx)
#define DSY_CLAMP(in, mn, mx) (DSY_MIN(DSY_MAX(in, mn), mx))
#define DSY_COUNTOF(_arr) (sizeof(_arr) / sizeof(_arr[0]))

static constexpr float kRandFrac = 1.f / (float)RAND_MAX;

static constexpr float kOneTwelfth = 1.f / 12.f;


inline float fclamp(float in, float min, float max)
{
    return fmin(fmax(in, min), max);
}


inline float fastpower(float f, int n)
{
    long *lp, l;
    lp = (long *)(&f);
    l  = *lp;
    l -= 0x3F800000;
    l <<= (n - 1);
    l += 0x3F800000;
    *lp = l;
    return f;
}

inline float fastroot(float f, int n)
{
    long *lp, l;
    lp = (long *)(&f);
    l  = *lp;
    l -= 0x3F800000;
    l >>= (n = 1);
    l += 0x3F800000;
    *lp = l;
    return f;
}

inline float pow10f(float f)
{
    return expf(2.302585092994046f * f);
}


inline float fastlog2f(float f)
{
    float frac;
    int   exp;
    frac = frexpf(fabsf(f), &exp);
    f    = 1.23149591368684f;
    f *= frac;
    f += -4.11852516267426f;
    f *= frac;
    f += 6.02197014179219f;
    f *= frac;
    f += -3.13396450166353f;
    f += exp;
    return (f);
}

inline float fastlog10f(float f)
{
    return fastlog2f(f) * 0.3010299956639812f;
}

inline float mtof(float m)
{
    return powf(2, (m - 69.0f) / 12.0f) * 440.0f;
}

inline void fonepole(float &out, float in, float coeff)
{
    out += coeff * (in - out);
}

enum class Mapping
{
    LINEAR,
    EXP,
    LOG,
};

inline float
fmap(float in, float min, float max, Mapping curve = Mapping::LINEAR)
{
    switch(curve)
    {
        case Mapping::EXP:
            return fclamp(min + (in * in) * (max - min), min, max);
        case Mapping::LOG:
        {
            const float a = 1.f / log10f(max / min);
            return fclamp(min * powf(10, in / a), min, max);
        }
        case Mapping::LINEAR:
        default: return fclamp(min + in * (max - min), min, max);
    }
}

template <typename T>
T median(T a, T b, T c)
{
    return (b < a) ? (b < c) ? (c < a) ? c : a : b
                   : (a < c) ? (c < b) ? c : b : a;
}

inline float ThisBlepSample(float t)
{
    return 0.5f * t * t;
}


inline float NextBlepSample(float t)
{
    t = 1.0f - t;
    return -0.5f * t * t;
}

inline float NextIntegratedBlepSample(float t)
{
    const float t1 = 0.5f * t;
    const float t2 = t1 * t1;
    const float t4 = t2 * t2;
    return 0.1875f - t1 + 1.5f * t2 - t4;
}

inline float ThisIntegratedBlepSample(float t)
{
    return NextIntegratedBlepSample(1.0f - t);
}

inline float SoftLimit(float x)
{
    return x * (27.f + x * x) / (27.f + 9.f * x * x);
}

inline float SoftClip(float x)
{
    if(x < -3.0f)
        return -1.0f;
    else if(x > 3.0f)
        return 1.0f;
    else
        return SoftLimit(x);
}

inline void TestFloat(float &x, float y = 0.f)
{
    if(!std::isnormal(x) && x != 0)
    {
#if defined(__arm__) && defined(DEBUG)
        asm("bkpt 255");
#else
        x = y;
#endif
    }
}

inline float soft_saturate(float in, float thresh)
{
    bool  flip;
    float val, out;
    out  = 0.f;
    flip = in < 0.0f;
    val  = flip ? -in : in;
    if(val < thresh)
    {
        out = in;
    }
    else if(val > 1.0f)
    {
        out = (thresh + 1.0f) / 2.0f;
        if(flip)
            out *= -1.0f;
    }
    else if(val > thresh)
    {
        float temp;
        temp = (val - thresh) / (1 - thresh);
        out  = thresh + (val - thresh) / (1.0f + (temp * temp));
        if(flip)
            out *= -1.0f;
    }
    return out;
}
constexpr bool is_power2(uint32_t x)
{
    return ((x - 1) & x) == 0;
}

#if __cplusplus <= 201103L
inline uint32_t get_next_power2(uint32_t x)
#else
constexpr uint32_t get_next_power2(uint32_t x)
#endif
{
    x--;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x++;

    assert(is_power2(x));
    return x;
}

#endif