//
// Created by Joe Bristow on 21/11/2025.
//

#ifndef DELAYDSP_H
#define DELAYDSP_H

#include "CircularBuffer.h"

/*
 * CONCEPT:
 * 1. Each sample from main audio buffer is saved into the delay buffer.
 * 2. The 'write' position tracks where to write the next sample, wrapping back to 0 when the buffer length is reached.
 * 3. The 'read' position tracks where to read delayed samples. It is 'x' samples behind the write position. The delay time determines the samples it is behind by.
 *
 * IMPLEMENTATION:
 * .processBlock() iterates through samples in audio buffer, combining them with samples stored in the delay buffer.
 * .prepare() uses the system's sample rate to establish how many samples long the delay is (through delayTime member).
 *
 * - Delay time determines how far back the
*/
class DelayDSP {
public:
    void prepare(const int numChannels, const float sampleRate);
    void processBlock(const int channel, juce::AudioBuffer<float>& audioBuffer, const int blockSize);
    void setDelayTime(const float delayTime) { m_delaySamples = convertSecondsToSamples(delayTime); }

private:
    CircularBuffer m_buffer {};
    float m_sampleRate {};

    int m_maxDelayTime {5};
    int m_delaySamples {};

    int convertSecondsToSamples(float seconds) { return static_cast<int>(seconds * m_sampleRate); }
};



#endif //DELAYDSP_H
