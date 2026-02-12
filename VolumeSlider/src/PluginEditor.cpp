#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor(&p),
      processorRef(p),
      freqSliderAttachment(processorRef.getState(), "freqHz", frequencySlider),
      gainSliderAttachment(processorRef.getState(), "gain", gainSlider),
      playButtonAttachment(processorRef.getState(), "play", playButton)
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

    addAndMakeVisible(frequencySlider);
    addAndMakeVisible(gainSlider);

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

    g.setColour(juce::Colour(0xffd0d0d0));
    g.drawRoundedRectangle(panel.toFloat(), 16.0f, 1.5f);
}

//==============================================================================
void AudioPluginAudioProcessorEditor::resized()
{
    constexpr int sliderSize  = 140;
    constexpr int labelHeight = 22;
    constexpr int padding     = 30;

    //================ CONTROL PANEL AREA =================
    auto panel = getLocalBounds()
                    .removeFromBottom(260)
                    .reduced(40);

    // Frequency (right)
    frequencySlider.setBounds(
        panel.getRight() - sliderSize,
        panel.getCentreY() - sliderSize / 2,
        sliderSize,
        sliderSize
    );

    frequencyLabel.setBounds(
        frequencySlider.getX(),
        frequencySlider.getY() - labelHeight,
        sliderSize,
        labelHeight
    );

    // Gain (left)
    gainSlider.setBounds(
        frequencySlider.getX() - sliderSize - padding,
        frequencySlider.getY(),
        sliderSize,
        sliderSize
    );

    gainLabel.setBounds(
        gainSlider.getX(),
        gainSlider.getY() - labelHeight,
        sliderSize,
        labelHeight
    );

    //================ BYPASS BUTTON (TOP-RIGHT) =================
    playButton.setBounds(
        getWidth() - 120,
        20,
        100,
        36
    );
}
