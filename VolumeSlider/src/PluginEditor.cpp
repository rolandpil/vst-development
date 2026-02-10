#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), freqSliderAttachment (processorRef.getState(), "freqHz", frequencySlider),
playButtonAttachment (processorRef.getState(), "play" , playButton)
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    addAndMakeVisible(square);

    frequencySlider.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    frequencySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 50);
    addAndMakeVisible(frequencySlider);


    playButton.setButtonText("Playing");
    playButton.setToggleState(true, juce::NotificationType::dontSendNotification);
    playButton.setClickingTogglesState(true);
    playButton.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::green);
    playButton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::red);

    playButton.onClick = [this]()
    {
        const bool isPlaying = playButton.getToggleState();
        playButton.setButtonText(isPlaying ? "Playing" : "Bypassed");

    };
    addAndMakeVisible(playButton);
    addAndMakeVisible(frequencyLabel);
    frequencyLabel.setJustificationType(juce::Justification::centred);


    setSize (600, 600);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    // g.drawFittedText("Volume Slider!", getLocalBounds(), juce::Justification::centred, 1);
}

void AudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor...
    square.setBounds(100,100,100,100);
    frequencySlider.setBounds(getWidth() / 2 - 50,getWidth() / 2 - 50,200,200);
    frequencyLabel.setBounds(getWidth() / 2 - 50,getWidth() / 2 - 100,100,50);

    playButton.setBounds(getWidth() / 2 - 50,getHeight() - 100,100,50);

}
