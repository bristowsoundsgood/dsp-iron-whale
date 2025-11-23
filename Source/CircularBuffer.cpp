//
// Created by Joe Bristow on 21/11/2025.
//

#include "CircularBuffer.h"

CircularBuffer::CircularBuffer()
{
}

CircularBuffer::CircularBuffer(const int numChannels, const int numSamples)
{
    m_buffer.setSize(numChannels, numSamples);
}

// Pushes sample to the buffer. The index is governed by the writePosition. Wrapping is handled automatically.
void CircularBuffer::write(const int channel, const float sample)
{
    m_buffer.addSample(channel, m_writePosition, sample);
    m_writePosition++;

    // Wrap writePosition if exceeds max buffer length
    if (m_writePosition > m_buffer.getNumSamples() - 1)
    {
        m_writePosition = 0;
    }
}

// Only return value if index is in bounds.
float CircularBuffer::read(const int channel, const int index) const
{
    if (index < 0 || index > m_buffer.getNumSamples() - 1)
    {
        return 0.0f;
    }

    else
    {
        const float sample =  m_buffer.getSample(channel, index);
        return sample;
    }
}

void CircularBuffer::clear()
{
    m_buffer.clear();
    m_writePosition = 0;
}




