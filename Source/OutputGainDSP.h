//
// Created by Joe on 09/11/2025.
//

#ifndef BSGDELAY_OUTPUTGAINDSP_H
#define BSGDELAY_OUTPUTGAINDSP_H

class OutputGainDSP
{
public:
    void processBlock(float* block, int blockSize);

    // Getters / Setters
    [[nodiscard]] float getGain() const { return m_gain; };
    void setGain(const float newGain) { m_gain = newGain; };
private:
    float m_gain {};
    float m_sampleRate {};
};


#endif //BSGDELAY_OUTPUTGAINDSP_H