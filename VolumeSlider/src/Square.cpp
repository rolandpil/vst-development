//
// Created by trick on 2/2/2026.
//

#include "Square.h"

void Square::paint(juce::Graphics& g)
{
    g.fillAll (juce::Colours::orangered);

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Foo.", getLocalBounds(), juce::Justification::centred, 1);
}
void Square::resized()
{

}