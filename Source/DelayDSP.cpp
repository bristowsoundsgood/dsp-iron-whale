//
// Created by Joe Bristow on 21/11/2025.
//

#include "DelayDSP.h"

// Sets max size of delay buffer.
void DelayDSP::prepare(const int numChannels, const float sampleRate)
{
    m_sampleRate = sampleRate;
    m_buffer.setSize(numChannels, static_cast<int>(m_maxDelayTime * sampleRate));
}

void DelayDSP::processBlock(const int channel, juce::AudioBuffer<float>& audioBuffer, const int blockSize)
{
    float* channelData = audioBuffer.getWritePointer(channel);

    for (int i = 0; i < blockSize; i++)
    {
        float currentSample = channelData[i];

        // Write sample to buffer
        m_buffer.write(channel, currentSample);
        if (currentSample > 0.0f) std::cout << "Written " << currentSample << " to the buffer" << '\n';

        // Combine current sample with delayed sample
        const float delayedSample = m_buffer.read(channel, m_buffer.getWritePosition() - m_delaySamples);
        if (delayedSample > 0.0f) std::cout << "Retrieved " << delayedSample << " from the buffer" << '\n';

        // Only use delayed sample if it contains information.
        if (delayedSample > 0.0f)
        {
            currentSample *= delayedSample;
        }
    }
}

