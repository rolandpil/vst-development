#pragma once

#include "PluginProcessor.h"
#include "Square.h"
#include <JuceHeader.h>

#include "CustomLookAndFeel.h"

//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    Square square;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioPluginAudioProcessor& processorRef;

    juce::Slider frequencySlider;
    juce::Slider gainSlider;

    juce::TextButton playButton;
    juce::Label frequencyLabel {"FrequencyLabel", "Frequency"};
    juce::Label gainLabel {"GainLabel", "Gain"};
    juce::AudioProcessorValueTreeState::SliderAttachment freqSliderAttachment;
    juce::AudioProcessorValueTreeState::SliderAttachment gainSliderAttachment;
    juce::AudioProcessorValueTreeState::ButtonAttachment playButtonAttachment;
    std::unique_ptr<CustomLookAndFeel> customLookAndFeel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
