//
// Created by Joe on 09/11/2025.
//

#ifndef BSGDELAY_OUTPUTGAINDSP_H
#define BSGDELAY_OUTPUTGAINDSP_H

class OutputGainDSP
{
public:
    void processBlock(float* block, int blockSize) const;

    // Getters / Setters
    [[nodiscard]] float getGainDB() const { return m_gainDB; };
    void setGainDB(const float newGainDB) { m_gainDB = newGainDB; };
private:
    float m_gainDB {};
    float m_sampleRate {};
};


#endif //BSGDELAY_OUTPUTGAINDSP_H