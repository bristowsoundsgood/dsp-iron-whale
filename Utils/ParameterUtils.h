//
// Created by Joe on 26/11/2025.
//

#ifndef BSGDELAY_PARAMETERUTILS_H
#define BSGDELAY_PARAMETERUTILS_H

#include <juce_audio_basics/juce_audio_basics.h>

class ParameterUtils
{
public:
    static juce::String adaptPrecisionMilliseconds(float value, int);
};


#endif //BSGDELAY_PARAMETERUTILS_H