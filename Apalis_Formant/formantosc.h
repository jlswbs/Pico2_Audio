#pragma once
#ifndef DSY_FORMANTOSCILLATOR_H
#define DSY_FORMANTOSCILLATOR_H

#include <stdint.h>

class FormantOscillator
{
  public:
    FormantOscillator() {}
    ~FormantOscillator() {}

    /** Initializes the FormantOscillator module.
        \param sample_rate - The sample rate of the audio engine being run. 
    */
    void Init(float sample_rate);

    /** Get the next sample
    */
    float Process();

    /** Set the formant frequency.
        \param freq Frequency in Hz
    */
    void SetFormantFreq(float freq);

    /** Set the carrier frequency. This is the "main" frequency.
        \param freq Frequency in Hz
    */
    void SetCarrierFreq(float freq);

    /** Set the amount of phase shift
        \param ps Typically 0-1. Works with other values though, including negative.
    */
    void SetPhaseShift(float ps);

  private:
    inline float Sine(float phase);
    inline float ThisBlepSample(float t);
    inline float NextBlepSample(float t);

    float carrier_phase_;
    float formant_phase_;
    float next_sample_;

    float carrier_frequency_;
    float formant_frequency_;
    float phase_shift_;
    float ps_inc_;

    float sample_rate_;

  };

#endif