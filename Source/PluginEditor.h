#pragma once

#include "PluginProcessor.h"
#include "PluginParameters.h"
#include <juce_gui_basics/juce_gui_basics.h>

//==============================================================================
namespace EditorDefaults
{
    static constexpr int DEFAULT_WINDOW_WIDTH {400};
    static constexpr int DEFAULT_WINDOW_HEIGHT {600};
    static constexpr int DEFAULT_SLIDER_WIDTH {150};
    static constexpr int DEFAULT_SLIDER_HEIGHT {150};
    static constexpr int DEFAULT_SLIDER_TBOX_WIDTH {70};
    static constexpr int DEFAULT_SLIDER_TBOX_HEIGHT {30};
    static constexpr bool DEFAULT_SLIDER_TBOX_READONLY {false};
};

class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioPluginAudioProcessor& processorRef;

    // Declare child components
    juce::Slider sldrOutGain;
    juce::Label lblOutGain;

    // Parameter attachments
    juce::AudioProcessorValueTreeState::SliderAttachment attOutGain;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
