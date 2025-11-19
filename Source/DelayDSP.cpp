//
// Created by Joe Bristow on 17/11/2025.
//

#include "DelayDSP.h"
#include <cmath>

DelayDSP::DelayDSP(CircularBuffer& delayBuffer) : m_delayBuffer(delayBuffer)
{
}

void DelayDSP::prepare(float sampleRate)
{
    m_sampleRate = sampleRate;
}

int DelayDSP::convertSecondsToSamples(const float seconds) const
{
    return static_cast<int>(floor(m_sampleRate * seconds));
}

void DelayDSP::processBlock(const int channel, float* block, const int blockSize) const
{
    for (int i = 0; i < blockSize; ++i)
    {
        block[i] *= m_delayBuffer.getSample(channel, i - m_delaySamples);
    }
}

