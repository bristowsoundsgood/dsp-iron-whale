//
// Created by Joe on 09/11/2025.
//

#ifndef BSGDELAY_GAINDSP_H
#define BSGDELAY_GAINDSP_H

class GainDSP
{
public:
    void processBlock(float* block, int blockSize) const;

    float dBToAmplitude(float dB) const;

    // Getters / Setters
    [[nodiscard]] float getGainDB() const { return m_gainDB; };
    void setGainDB(const float newGainDB) { m_gainDB = newGainDB; };
private:
    float m_gainDB {};
    float m_sampleRate {};
};


#endif //BSGDELAY_GAINDSP_H