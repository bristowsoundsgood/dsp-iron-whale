//
// Created by Joe Bristow on 04/12/2025.
//

#include "DefaultSkin.h"

juce::Typeface::Ptr Text::Fonts::getTypeface()
{
    return juce::Typeface::createSystemTypefaceFor(BinaryData::IBMPlexSans_ttf, BinaryData::IBMPlexSans_ttfSize);
}

juce::Font Text::Fonts::getFont(const float height)
{
    return juce::Font(getTypeface()).withHeight(height);
}

MainLookAndFeel::MainLookAndFeel()
{
    setDefaultSansSerifTypeface(Text::Fonts::getTypeface());
    setColour(juce::GroupComponent::ColourIds::outlineColourId, Colours::GroupComponent::outline);
    setDefaultLookAndFeel(this);
}

MainLookAndFeel::~MainLookAndFeel()
{
    setDefaultLookAndFeel(nullptr);
}

MainLookAndFeel& MainLookAndFeel::instance()
{
    static MainLookAndFeel INSTANCE;
    return INSTANCE;
}

RotaryDialLookAndFeel::RotaryDialLookAndFeel()
{
    setColour(juce::Slider::rotarySliderFillColourId, Colours::Dial::dialFill);
}

RotaryDialLookAndFeel& RotaryDialLookAndFeel::instance()
{
    static RotaryDialLookAndFeel INSTANCE;
    return INSTANCE;
}







