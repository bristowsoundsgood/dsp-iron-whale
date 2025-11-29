//
// Created by Joe on 26/11/2025.
//

#include "ParameterUtils.h"

// Precision depends on value magnitude
juce::String ParameterUtils::adaptPrecisionMilliseconds(const float value, int)
{
    if (value < 10.0f)
    {
        return juce::String(value, 2) + " ms";
    }

    else if (value < 100.0f)
    {
        return juce::String(value, 1) + " ms";
    }

    else if (value < 1000.0f)
    {
        return juce::String(static_cast<int>(value)) + " ms";
    }

    else
    {
        return juce::String(value * 0.001f, 2) + " s";
    }
}
