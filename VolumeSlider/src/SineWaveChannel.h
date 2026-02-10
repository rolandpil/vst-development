//
// Created by trick on 2/3/2026.
//

#ifndef VOLUMESLIDER_SINEWAVECHANNEL_H
#define VOLUMESLIDER_SINEWAVECHANNEL_H

#include <cmath>
#include <numbers>

#include <JuceHeader.h>


class SineWaveChannel
{
public:
    void prepare (double sampleRate);
    void process (float* output, int numSamples);

    [[nodiscard]] float getAmplitude() const {return amplitude;}
    [[nodiscard]] float getFrequency() {return smoothedFreq.getTargetValue();}
    void setAmplitude(const float newAmplitude) {amplitude = newAmplitude;}
    void setFrequency(const float newFrequency) {smoothedFreq.setTargetValue(newFrequency);}

private:
    float amplitude = 0.05f;
    float currentSampleRate = 0.0f;
    float timeIncrement = 0.0f;
    float currentTime = 0.0f;
    float phase = 0.0f;
    juce::SmoothedValue<float, juce::ValueSmoothingTypes::Multiplicative> smoothedFreq;
};


#endif //VOLUMESLIDER_SINEWAVECHANNEL_H