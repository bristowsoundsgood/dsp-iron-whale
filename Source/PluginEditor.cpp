#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <juce_gui_basics/juce_gui_basics.h>

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), attOutGain(p.getProcessorValueTreeState(), PluginConfig::paramIDOutGain.getParamID(), sldrOutGain)
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (EditorDefaults::DEFAULT_WINDOW_WIDTH, EditorDefaults::DEFAULT_WINDOW_HEIGHT);

    // Add + configure child components
    addAndMakeVisible(sldrOutGain);
    addAndMakeVisible(lblOutGain);

    sldrOutGain.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    sldrOutGain.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, EditorDefaults::DEFAULT_SLIDER_TBOX_READONLY, EditorDefaults::DEFAULT_SLIDER_TBOX_WIDTH, EditorDefaults::DEFAULT_SLIDER_TBOX_HEIGHT);
    sldrOutGain.setRange(PluginConfig::minOutGain, PluginConfig::maxOutGain, PluginConfig::defaultSliderStep);
    sldrOutGain.setTextValueSuffix("dB");
    lblOutGain.setText("Output Gain", juce::NotificationType::dontSendNotification);
    lblOutGain.attachToComponent(&sldrOutGain, true);
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
    sldrOutGain.setBounds(bounds.getCentreX() - EditorDefaults::DEFAULT_SLIDER_WIDTH / 2, bounds.getCentreY() - EditorDefaults::DEFAULT_SLIDER_HEIGHT / 2,
                             EditorDefaults::DEFAULT_SLIDER_WIDTH, EditorDefaults::DEFAULT_SLIDER_HEIGHT);
}
