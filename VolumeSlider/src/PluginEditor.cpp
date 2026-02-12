#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), freqSliderAttachment(processorRef.getState(),"freqHz",frequencySlider), playButtonAttachment(processorRef.getState(),"play",playButton)
{
    //================ SLIDERS =================
    auto setupKnob = [](juce::Slider& s)
    {
        s.setSliderStyle(juce::Slider::RotaryVerticalDrag);
        s.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 70, 22);
        s.setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
    };

    setupKnob(frequencySlider);
    setupKnob(gainSlider);

    frequencySlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    frequencySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 50);
    addAndMakeVisible(frequencySlider);

    playButton.setButtonText("Playing");
    playButton.setToggleState(true,juce::NotificationType::dontSendNotification);
    playButton.setClickingTogglesState(true);

    playButton.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::green);
    playButton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::red);

    playButton.onClick = [this]()
    {
        // Change the state of the button when it's clicked
        const bool isPlaying = playButton.getToggleState();
        playButton.setButtonText(isPlaying ? "Playing" : "Bypassed");
    };
    addAndMakeVisible(playButton);

    frequencyLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(frequencyLabel);

    setSize (400, 400);
}

    //================ LABELS =================
    auto setupLabel = [](juce::Label& l, const juce::String& text)
    {
        l.setText(text, juce::dontSendNotification);
        l.setJustificationType(juce::Justification::centred);
        l.setColour(juce::Label::textColourId, juce::Colours::darkgrey);
    };

    setupLabel(frequencyLabel, "Frequency");
    setupLabel(gainLabel, "Gain");

    addAndMakeVisible(frequencyLabel);
    addAndMakeVisible(gainLabel);

    //================ BYPASS BUTTON =================
    playButton.setClickingTogglesState(true);
    playButton.setToggleState(true, juce::dontSendNotification);
    playButton.setButtonText("On");

    playButton.setColour(juce::TextButton::buttonOnColourId, juce::Colours::seagreen);
    playButton.setColour(juce::TextButton::buttonColourId, juce::Colours::darkred);
    playButton.setColour(juce::TextButton::textColourOffId, juce::Colours::white);
    playButton.setColour(juce::TextButton::textColourOnId, juce::Colours::white);

    playButton.onClick = [this]()
    {
        playButton.setButtonText(
            playButton.getToggleState() ? "On" : "Bypass"
        );
    };

    addAndMakeVisible(playButton);

    //================ WINDOW =================
    customLookAndFeel = std::make_unique<CustomLookAndFeel>();

    // Apply to entire editor (recommended)
    setLookAndFeel(customLookAndFeel.get());

    setSize(600, 600);}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor() {
    setLookAndFeel(nullptr);
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // Background
    g.fillAll(juce::Colour(0xfff2f2f2));

    // Control panel
    auto panel = getLocalBounds()
                    .removeFromBottom(260)
                    .reduced(40);

    g.setColour(juce::Colour(0xffffffff));
    g.fillRoundedRectangle(panel.toFloat(), 16.0f);

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("First Plugin", getLocalBounds(), juce::Justification::centred, 1);
}

//==============================================================================
void AudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor...
    square.setBounds(10,10,10,10);
    frequencySlider.setBounds(getWidth() / 2 - 100,getHeight() / 2 - 100,200,200);
    playButton.setBounds(getWidth() / 2 - 50,getHeight() / 2 + 100,100,20);
    frequencyLabel.setBounds(getWidth() / 2 - 50,getHeight() / 2 + 130,100,20);

}
