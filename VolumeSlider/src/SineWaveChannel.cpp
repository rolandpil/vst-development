//
// Created by trick on 2/3/2026.
//
#include <cmath>
#include <numbers>
#include "SineWaveChannel.h"

void SineWaveChannel::prepare(double sampleRate)
{
    currentSampleRate = static_cast<float>(sampleRate);
    phase = 0.0f;

    smoothedFreq.reset(sampleRate, 0.02f);
    smoothedFreq.setCurrentAndTargetValue(440.0f);
}

void SineWaveChannel::process(float* output, int numSamples)
{
    for (int i = 0; i < numSamples; ++i) // generate one sine wave at a time per each sample
    {
        const float freq = smoothedFreq.getNextValue(); // get the next frequency to generate the wave at (smoothed)

        //phase increment equation: 0-2pi is one full cycle of the wave
        //This calculates how much phase of this wave should move forward during this sample
        const float phaseInc =  juce::MathConstants<float>::twoPi * freq / currentSampleRate;

        output[i] = amplitude * std::sinf(phase); // sinewave equation: A * sin(phase)

        phase += phaseInc; // advance the current phase pointer
        //wrap the phrase in the range 0-2pi, cant go over.
        if (phase >= juce::MathConstants<float>::twoPi)
            phase -= juce::MathConstants<float>::twoPi;
    }
}


