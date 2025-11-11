//
// Created by Joe on 09/11/2025.
//

#include "GainDSP.h"
#include <cmath>

float GainDSP::dBToAmplitude(float dB) const
{
    return static_cast<float>(pow(10, (dB / 20)));
}


void GainDSP::processBlock(float* block, const int blockSize) const
{
    const float amplitudeGain = dBToAmplitude(m_gainDB);

    // Scale sample amplitude
    for (int sample = 0; sample < blockSize; ++sample)
    {
        block[sample] *= amplitudeGain;
    }
}