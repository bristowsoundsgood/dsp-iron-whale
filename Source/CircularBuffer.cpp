//
// Created by Joe Bristow on 17/11/2025.
//

#include "CircularBuffer.h"

void CircularBuffer::processBlock(const int channel, const juce::AudioBuffer<float>& block, const int blockSize)
{
    const int bufferSize = buffer.getNumSamples();

    // Write each sample to buffer
    // If index exceeds buffer length, then wrap back to 0 and continue

     for (int i = 0; i < blockSize; ++i)
     {
         if (writePosition <= bufferSize - 1)
         {
            buffer.addSample(channel, writePosition, block.getSample(channel, i));
         }

         else if (writePosition > bufferSize - 1)
         {
             writePosition = 0;
             buffer.addSample(channel, writePosition, block.getSample(channel, i));
         }

         writePosition++;
     }
}