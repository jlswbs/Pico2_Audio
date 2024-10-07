#pragma once
#ifndef DSY_VOSIM_H
#define DSY_VOSIM_H

#include <stdint.h>

class VosimOscillator
{
  public:
    VosimOscillator() {}
    ~VosimOscillator() {}

    /** Initializes the FormantOscillator module.
        \param sample_rate - The sample rate of the audio engine being run. 
    */
    void Init(float sample_rate);

    /** Get the next sample
    */
    float Process();

    /** Set carrier frequency.
        \param freq Frequency in Hz.
    */
    void SetFreq(float freq);

    /** Set formant 1 frequency.
        \param freq Frequency in Hz.
    */
    void SetForm1Freq(float freq);

    /** Set formant 2 frequency.
        \param freq Frequency in Hz.
    */
    void SetForm2Freq(float freq);

    /** Waveshaping
        \param shape Shape to set. Works -1 to 1
    */
    void SetShape(float shape);

  private:
    float Sine(float phase);

    float sample_rate_;

    float carrier_phase_;
    float formant_1_phase_;
    float formant_2_phase_;

    float carrier_frequency_;
    float formant_1_frequency_;
    float formant_2_frequency_;
    float carrier_shape_;
};

#endif