#pragma once
#include <JuceHeader.h>

class CustomLookAndFeel : public juce::LookAndFeel_V4
{
public:
    CustomLookAndFeel();
    ~CustomLookAndFeel() override = default;

    // Rotary slider
    void drawRotarySlider(juce::Graphics& g,
                          int x, int y, int width, int height,
                          float sliderPos,
                          float rotaryStartAngle,
                          float rotaryEndAngle,
                          juce::Slider& slider) override;

    // Fonts
    juce::Font getLabelFont(juce::Label& label) override;
    juce::Font getTextButtonFont(juce::TextButton& button, int buttonHeight) override;

    // Custom slider layout to control textbox size & position
    juce::Slider::SliderLayout getSliderLayout(juce::Slider& slider) override;

private:
    juce::Font uiFont;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CustomLookAndFeel)
};
