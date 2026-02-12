#pragma once
#include <JuceHeader.h>

class CustomLookAndFeel : public juce::LookAndFeel_V4
{
public:
    CustomLookAndFeel();
    ~CustomLookAndFeel() override = default;

    void drawRotarySlider(juce::Graphics& g,
                          int x, int y, int width, int height,
                          float sliderPos,
                          float rotaryStartAngle,
                          float rotaryEndAngle,
                          juce::Slider& slider) override;

    juce::Font getLabelFont(juce::Label& l) override;
    juce::Font getTextButtonFont(juce::TextButton& b, int buttonHeight) override;
    juce::Font getSliderTextBoxFont(juce::Slider& s);  // <-- MUST be here

private:
    juce::Font uiFont;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CustomLookAndFeel)
};
