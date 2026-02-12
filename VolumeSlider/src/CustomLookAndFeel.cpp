#include "CustomLookAndFeel.h"
#include "BinaryData.h" // Make sure this include path exists

CustomLookAndFeel::CustomLookAndFeel()
{
    // Load the font from BinaryData (sanitized symbol names)
    auto typeface = juce::Typeface::createSystemTypefaceFor(
        BinaryData::helveticadestrupix_ttf,
        BinaryData::helveticadestrupix_ttfSize
    );

    // Store in uiFont for reuse
    uiFont = juce::Font(typeface).withHeight(20.0f);

    // Optional: customize slider, button, etc. colours here
    setColour(juce::Slider::thumbColourId, juce::Colours::darkgrey);
    setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::white);
    setColour(juce::TextButton::buttonColourId, juce::Colours::darkred);
    setColour(juce::TextButton::buttonOnColourId, juce::Colours::seagreen);
}

//----------------------------- ROTARY SLIDER -----------------------------
void CustomLookAndFeel::drawRotarySlider(juce::Graphics& g,
                                         int x, int y, int width, int height,
                                         float sliderPos,
                                         float rotaryStartAngle,
                                         float rotaryEndAngle,
                                         juce::Slider& slider)
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
    g.fillPath(p, juce::AffineTransform::rotation(angle)
                       .translated(centreX, centreY));
}

//----------------------------- FONTS -----------------------------
juce::Font CustomLookAndFeel::getLabelFont(juce::Label&)
{
    return uiFont;
}

juce::Font CustomLookAndFeel::getTextButtonFont(juce::TextButton&, int)
{
    return uiFont.withHeight(13.0f);
}

juce::Font CustomLookAndFeel::getSliderTextBoxFont(juce::Slider&)
{
    return uiFont.withHeight(12.0f);
}
