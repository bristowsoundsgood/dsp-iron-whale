#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_gui_basics/juce_gui_basics.h>

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (DelayPluginProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), attOutGain(p.getProcessorValueTreeState(), PluginConfig::paramIDOutGain.getParamID(), sldrOutGain),
        attFeedback(p.getProcessorValueTreeState(), PluginConfig::paramIDDelayTime.getParamID(), sldrFeedback)
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (EditorDefaults::defaultWindowWidth, EditorDefaults::defaultWindowHeight);

    // Add + configure child components
    addAndMakeVisible(sldrOutGain);
    addAndMakeVisible(lblOutGain);
    addAndMakeVisible(sldrFeedback);
    addAndMakeVisible(lblFeedback);

    sldrOutGain.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    sldrOutGain.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, EditorDefaults::defaultSliderTextBoxReadOnly, EditorDefaults::defaultSliderTextBoxWidth, EditorDefaults::defaultSliderTextBoxHeight);
    sldrOutGain.setRange(PluginConfig::minOutGain, PluginConfig::maxOutGain, PluginConfig::defaultSliderStep);
    sldrOutGain.setTextValueSuffix("dB");
    lblOutGain.setText(PluginConfig::paramNameOutGain, juce::NotificationType::dontSendNotification);
    lblOutGain.attachToComponent(&sldrOutGain, true);

    sldrFeedback.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    sldrFeedback.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, EditorDefaults::defaultSliderTextBoxReadOnly, EditorDefaults::defaultSliderTextBoxWidth, EditorDefaults::defaultSliderTextBoxHeight);
    sldrFeedback.setRange(PluginConfig::minDelayTime, PluginConfig::maxDelayTime, PluginConfig::defaultSliderStep);
    sldrFeedback.setTextValueSuffix("s");
    lblFeedback.setText(PluginConfig::paramNameDelayTime, juce::NotificationType::dontSendNotification);
    lblFeedback.attachToComponent(&sldrFeedback, true);
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
}

void AudioPluginAudioProcessorEditor::resized()
{
    const juce::Rectangle<int> bounds = getLocalBounds();

    // Lay out child components

    sldrFeedback.setBounds(bounds.getCentreX() - EditorDefaults::defaultSliderWidth / 2, bounds.getCentreY() - EditorDefaults::defaultSliderHeight / 2,
                             EditorDefaults::defaultSliderWidth, EditorDefaults::defaultSliderHeight);

    sldrOutGain.setBounds(bounds.getCentreX() - EditorDefaults::defaultSliderWidth / 2, (bounds.getCentreY() - EditorDefaults::defaultSliderHeight / 2) + EditorDefaults::sliderMarginY,
        EditorDefaults::defaultSliderWidth, EditorDefaults::defaultSliderHeight);
}
