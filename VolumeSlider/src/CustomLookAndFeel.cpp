#include "CustomLookAndFeel.h"
#include "BinaryData.h"

CustomLookAndFeel::CustomLookAndFeel()
{
    // Load your custom font from BinaryData
    auto typeface = juce::Typeface::createSystemTypefaceFor(
        BinaryData::Metropolitan_ttf,
        BinaryData::Metropolitan_ttfSize
    );

    uiFont = juce::Font(typeface).withHeight(14.0f);

    // Slider colors
    setColour(juce::Slider::thumbColourId, juce::Colours::darkgrey);
    setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::white);

    // Button colors
    setColour(juce::TextButton::buttonColourId, juce::Colours::darkred);
    setColour(juce::TextButton::buttonOnColourId, juce::Colour::fromHSV(0.75f, 0.5f, 0.7f, 1.0f)); // purple-ish
}

//----------------------------- ROTARY SLIDER -----------------------------
void CustomLookAndFeel::drawRotarySlider(juce::Graphics& g,
                                         int x, int y, int width, int height,
                                         float sliderPos,
                                         float rotaryStartAngle,
                                         float rotaryEndAngle,
                                         juce::Slider&)
{
    auto radius  = juce::jmin(width, height) / 2.0f - 6.0f;
    auto centreX = x + width  * 0.5f;
    auto centreY = y + height * 0.5f;
    auto angle   = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

    // Knob body
    g.setColour(juce::Colours::darkgrey);
    g.fillEllipse(centreX - radius, centreY - radius, radius * 2, radius * 2);

    // Knob indicator
    juce::Path p;
    p.addRectangle(-2.0f, -radius, 4.0f, radius * 0.6f);
    g.setColour(juce::Colours::white);
    g.fillPath(p, juce::AffineTransform::rotation(angle).translated(centreX, centreY));
}

//----------------------------- FONTS -----------------------------
juce::Font CustomLookAndFeel::getLabelFont(juce::Label&)
{
    return uiFont.withHeight(30.0f);
}

juce::Font CustomLookAndFeel::getTextButtonFont(juce::TextButton&, int)
{
    return uiFont.withHeight(30.0f);
}

//----------------------------- SLIDER LAYOUT -----------------------------
juce::Slider::SliderLayout CustomLookAndFeel::getSliderLayout(juce::Slider& slider)
{
    juce::Slider::SliderLayout layout;

    // Knob takes full bounds
    layout.sliderBounds = slider.getLocalBounds();

    // Text box centered below knob
    layout.textBoxBounds = slider.getLocalBounds()
                                .withSizeKeepingCentre(80, 22)
                                .withY(slider.getHeight() - 25);

    return layout;
}
