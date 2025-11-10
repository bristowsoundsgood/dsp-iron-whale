//
// Created by Joe on 09/11/2025.
//

#include "OutputGainDSP.h"
#include <juce_audio_basics/juce_audio_basics.h>

void OutputGainDSP::processBlock(float* block, const int blockSize) const
{
    const float gain = juce::Decibels::decibelsToGain(m_gainDB);

    // Scale sample amplitude
    for (int sample = 0; sample < blockSize; ++sample)
    {
        block[sample] *= gain;
    }
}
