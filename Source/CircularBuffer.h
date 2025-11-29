//
// Created by Joe Bristow on 21/11/2025.
//

#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <juce_audio_basics/juce_audio_basics.h>

class CircularBuffer {
public:
    CircularBuffer();
    CircularBuffer(const int numChannels, const int numSamples);

    void write(const int channel, const float sample);
    float read(const int channel, const int index) const;
    void clear();

    void setSize(const int numChannels, const int numSamples) { m_buffer.setSize(numChannels, numSamples); }
    int getSize() const { return m_buffer.getNumSamples(); }


    int getWritePosition() const { return m_writePosition; }

private:
    juce::AudioBuffer<float> m_buffer {};
    int m_writePosition {0};
};



#endif //CIRCULARBUFFER_H
