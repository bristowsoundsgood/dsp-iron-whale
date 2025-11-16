//
// Created by Joe Bristow on 14/11/2025.
//

#include "PluginParameters.h"

PluginParameters::PluginParameters(const juce::AudioProcessorValueTreeState& stateManager)
{
    // Store the memory addresses of each parameter object upon construction.
    m_paramOutGain = dynamic_cast<juce::AudioParameterFloat*>(stateManager.getParameter(PluginConfig::paramIDOutGain.getParamID()));
}

// Sets the sample rate and ramp time for the parameter smoothers
void PluginParameters::prepare(const double sampleRate) noexcept
{
    m_smootherGain.reset(sampleRate, PluginConfig::rampOutGain);
}

void PluginParameters::reset() noexcept
{
    m_smootherGain.setCurrentAndTargetValue(m_paramOutGain->get());
}

void PluginParameters::update() noexcept
{
    m_smootherGain.setTargetValue(m_paramOutGain->get());
}

juce::AudioProcessorValueTreeState::ParameterLayout PluginParameters::createParameterLayout() noexcept
{
    return {
        std::make_unique<juce::AudioParameterFloat> (PluginConfig::paramIDOutGain, PluginConfig::paramNameOutGain, PluginConfig::minOutGain, PluginConfig::maxOutGain, PluginConfig::defaultOutGain)
    };
}
