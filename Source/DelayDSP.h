//
// Created by Joe Bristow on 17/11/2025.
//

#pragma once
#ifndef DELAYDSP_H
#define DELAYDSP_H

#include "CircularBuffer.h"

class DelayDSP {
public:
    DelayDSP(CircularBuffer& delayBuffer);
    int convertSecondsToSamples(float seconds) const;
    void setDelayTime(const float delaySeconds) { m_delaySamples = convertSecondsToSamples(delaySeconds); }

    void prepare(float sampleRate);
    void processBlock(const int channel, float* block, const int blockSize) const;

private:
    float m_sampleRate {};
    int m_delaySamples {};
    CircularBuffer& m_delayBuffer;
};


#endif //DELAYDSP_H
