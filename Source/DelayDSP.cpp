//
// Created by Joe Bristow on 21/11/2025.
//

#include "DelayDSP.h"

/*
 * FIXES NEEDED:
 * - Delay time is not correct
 * - Delay is not consistent
 */

int sampleCounter {0};

bool areEqualAbs(const float a, const float b, const float epsilon = 0.00001f)
{
    return (fabs(a - b) <= epsilon);
}

// Sets max size of delay buffer.
void DelayDSP::prepare(const int numChannels, const float sampleRate)
{
    m_sampleRate = sampleRate;
    m_buffer.setSize(numChannels, static_cast<int>(m_maxDelayTime * m_sampleRate));
}

void DelayDSP::processBlock(const int channel, float* block, const int blockSize)
{
    for (int i = 0; i < blockSize; i++)
    {
        float& currentSample = block[i];

        // Write sample to buffer
        m_buffer.write(channel, currentSample);

        if (areEqualAbs(currentSample, 0.018709f))
        {
            std::cout << "WRITE: 0 samples in" << '\n';
            sampleCounter = 0;
        }

        // Combine current sample with delayed sample
        const int readIndex = m_buffer.getWritePosition() - m_delaySamples;
        const float delayedSample = m_buffer.read(channel, readIndex);

        if (areEqualAbs(delayedSample, 0.018709f))
        {
            std::cout << "READ: occurred " << sampleCounter << " samples after playback" << '\n';
        }

        // Only use delayed sample if it contains information.
        if (delayedSample != 0.0f)
        {
            currentSample = delayedSample;
        }

        sampleCounter++;
    }
}

void DelayDSP::clear()
{
    m_buffer.clear();
}


