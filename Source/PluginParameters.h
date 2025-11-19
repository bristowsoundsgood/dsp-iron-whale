//
// Created by Joe Bristow on 14/11/2025.
//
#pragma once
#ifndef PLUGINPARAMETERS_H
#define PLUGINPARAMETERS_H
#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_audio_basics/juce_audio_basics.h>

namespace PluginConfig
{
    // Parameter settings
    static constexpr float defaultSliderStep {0.01f};

    static constexpr float minOutGain {-64.0f};
    static constexpr float maxOutGain {24.0f};
    static constexpr float defaultOutGain {0.0f};
    static const juce::ParameterID paramIDOutGain {"outputGain", 1};
    static const juce::String paramNameOutGain {"Output Gain"};

    static constexpr float minFeedback {0.0f};
    static constexpr float maxFeedback {2.0f};
    static constexpr float defaultFeedback {0.0f};
    static const juce::ParameterID paramIDFeedback {"delayFeedback", 1};
    static const juce::String paramNameFeedback {"Delay Feedback"};

    // SmoothedValue settings
    static constexpr float rampOutGain {0.001f};
}

class PluginParameters
{
public:
    // Accepts APVTS as dependency to store the addresses of the parameters found in state manager
    PluginParameters(const juce::AudioProcessorValueTreeState& stateManager);

    // Called upon PluginProcessor initialisation
    [[nodiscard]] static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout() noexcept;

    // Accessor methods
    [[nodiscard]] float getOutputGainValue() { return m_smootherGain.getNextValue(); }
    [[nodiscard]] float getDelayTime() const { return m_paramDelayTime->get(); }

    // Parameter smoothing methods
    void prepare(double sampleRate) noexcept;
    void reset() noexcept;
    void update() noexcept;

private:
    juce::AudioParameterFloat* m_paramOutGain {};
    juce::AudioParameterFloat* m_paramDelayTime {};
    juce::SmoothedValue<float, juce::ValueSmoothingTypes::Linear> m_smootherGain {};
};

#endif //PLUGINPARAMETERS_H
