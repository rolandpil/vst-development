//
// Created by trick on 2/3/2026.
//

#include "SineWaveChannel.h"

void SineWaveChannel::prepare (const double sampleRate)
{
    currentSampleRate = static_cast<float>(sampleRate);
    phase = 0.0f;

    smoothedFreq.reset(sampleRate, 0.2f);
    smoothedFreq.setCurrentAndTargetValue(440.0f);
}

void SineWaveChannel::process(float* output, int numSamples)
{

    for (int sample = 0; sample < numSamples; ++sample)
    {
        const float freq = smoothedFreq.getNextValue();
        const float phaseInc =
            juce::MathConstants<float>::twoPi * freq / currentSampleRate;

        output[sample] = amplitude * std::sinf(phase);

        phase += phaseInc;
        if (phase >= juce::MathConstants<float>::twoPi)
            phase -= juce::MathConstants<float>::twoPi;

    }
}
