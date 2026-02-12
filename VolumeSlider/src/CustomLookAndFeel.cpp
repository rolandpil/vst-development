#include "CustomLookAndFeel.h"

void CustomLookAndFeel::drawRotarySlider(juce::Graphics& g,
                                        int x, int y, int width, int height,
                                        float sliderPos,
                                        float rotaryStartAngle,
                                        float rotaryEndAngle,
                                        juce::Slider& slider)
{
    auto radius = juce::jmin(width, height) / 2.0f - 6.0f;
    auto centreX = x + width  * 0.5f;
    auto centreY = y + height * 0.5f;
    auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

    // Knob body
    g.setColour(juce::Colours::darkgrey);
    g.fillEllipse(centreX - radius, centreY - radius, radius * 2, radius * 2);

    // Indicator
    juce::Path p;
    p.addRectangle(-2.0f, -radius, 4.0f, radius * 0.6f);

    g.setColour(juce::Colours::white);
    g.fillPath(p, juce::AffineTransform::rotation(angle)
                      .translated(centreX, centreY));
}
