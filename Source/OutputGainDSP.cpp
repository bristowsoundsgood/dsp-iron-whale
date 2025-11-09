//
// Created by Joe on 09/11/2025.
//

#include "OutputGainDSP.h"

void OutputGainDSP::processBlock(float* block, const int blockSize)
{
    // Scale sample amplitude
    for (int sample = 0; sample < blockSize; ++sample)
    {
        block[sample] = block[sample] * m_gain;
    }
}
