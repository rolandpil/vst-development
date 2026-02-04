//
// Created by trick on 2/3/2026.
//

#include "SineWaveChannel.h"

void SineWaveChannel::prepare (const double sampleRate)
{
    currentSampleRate = static_cast<float>(sampleRate);
    timeIncrement = 1.0f / currentSampleRate;
}

void SineWaveChannel::process(float* output, int numSamples)
{

    for (int sample = 0; sample < numSamples; ++sample)
    {
        output[sample] = amplitude * std::sinf(2.0f * std::numbers::pi_v<float> * frequency * currentTime);
        currentTime += timeIncrement;
    }
}
