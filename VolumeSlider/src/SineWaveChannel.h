//
// Created by trick on 2/3/2026.
//

#ifndef VOLUMESLIDER_SINEWAVECHANNEL_H
#define VOLUMESLIDER_SINEWAVECHANNEL_H



#include <JuceHeader.h>


class SineWaveChannel
{
public:
    void prepare (double sampleRate);
    void process (float* output, int numSamples);

    [[nodiscard]] float getAmplitude() const {return amplitude;}
    [[nodiscard]] float getFrequency() const
    {
        return smoothedFreq.getTargetValue();
    }
    void setAmplitude(const float newAmplitude) {amplitude = newAmplitude;}
    void setFrequency(const float newFrequency) {smoothedFreq.setTargetValue(newFrequency); }

private:
    float amplitude = 20.00f;
    float currentSampleRate = 0.0f;
    float phase = 0.0f;
    juce::LinearSmoothedValue<float> ex1;
    juce::SmoothedValue<float, juce::ValueSmoothingTypes::Multiplicative> smoothedFreq; // better for freq than linear smoothed value
};


#endif //VOLUMESLIDER_SINEWAVECHANNEL_H