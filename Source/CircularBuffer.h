//
// Created by Joe Bristow on 17/11/2025.
//

#pragma once
#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <juce_audio_basics/juce_audio_basics.h>

class CircularBuffer {
public:
    void setSize(const int numChannels, const int numSamples) { buffer.setSize(numChannels, numSamples); }
    float getSample(const int channel, const int sampleIndex) const { return buffer.getSample(channel, sampleIndex); }
    void processBlock(const int channel, const juce::AudioBuffer<float>& block, const int blockSize);

private:
    int writePosition {0};
    juce::AudioBuffer<float> buffer {};
};

#endif //CIRCULARBUFFER_H
