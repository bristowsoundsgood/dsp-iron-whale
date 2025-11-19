//
// Created by Joe Bristow on 18/11/2025.
//

#include <numeric>
#include "../Source/CircularBuffer.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_all.hpp>

// 1. Write to buffer without wrapping
// 2. Write to buffer without wrapping (maximum)
// 3. Write to buffer with wrapping (exceed maximum)

CircularBuffer ringBuffer {};
constexpr double EPSILON {1e-9};
constexpr int numChannels {1};
constexpr int blockSize {3};
constexpr int ringBufferSize {blockSize};

constexpr int idxFirst {0};
constexpr int idxLast {blockSize - 1};

TEST_CASE("Circular Buffer: Initialisation", "[circularBuffer]")
{
    ringBuffer.setSize(numChannels, ringBufferSize);

    // Test that we can read from any position
    REQUIRE_THAT(ringBuffer.getSample(numChannels - 1, idxFirst), Catch::Matchers::WithinAbs(idxFirst, EPSILON));
    REQUIRE_THAT(ringBuffer.getSample(numChannels - 1, idxLast), Catch::Matchers::WithinAbs(idxLast, EPSILON));
}

TEST_CASE("Circular Buffer: Write to Buffer Without Wrapping", "[circularBuffer]")
{
    ringBuffer.setSize(numChannels, ringBufferSize);

    // Create dummy samples
    std::vector<float> samples (blockSize); // 3 samples total (block size of 3)
    std::iota(samples.begin(), samples.end(), 0);
    float* ptrSamples = samples.data();

    // Create block from dummy samples
    const juce::AudioBuffer<float> block {&ptrSamples, numChannels, blockSize};

    // Fill ring buffer from block
    ringBuffer.processBlock(numChannels - 1, block, blockSize);

    // Verify block contains all samples
    REQUIRE_THAT(ringBuffer.getSample(numChannels - 1, 0), Catch::Matchers::WithinAbs(0, EPSILON));
    REQUIRE_THAT(ringBuffer.getSample(numChannels - 1, blockSize - 1), Catch::Matchers::WithinAbs(blockSize - 1, EPSILON));
}

TEST_CASE("Circular Buffer: Write to Buffer With Wrapping", "[circularBuffer]")
{
    // [0, 1, 2] -> [3, 1, 2]
    ringBuffer.setSize(numChannels, ringBufferSize);

    // Create dummy samples [0, 1, 2]
    std::vector<float> samples (blockSize);
    std::iota(samples.begin(), samples.end(), 0);
    float* ptrSamples = samples.data();
    const juce::AudioBuffer<float> block = {&ptrSamples, numChannels, blockSize};

    // Fill ring buffer from block. This fills up the buffer, leaving no remaining space.
    ringBuffer.processBlock(numChannels - 1, block, blockSize);

    // Add another sample to the ring buffer. The expected behaviour is that it wraps writing back to the first index, overwriting the first value.
    std::vector<float> finalSamples {3.0f};
    float* ptrFinalSamples = finalSamples.data();
    const juce::AudioBuffer<float> finalBlock = {&ptrFinalSamples, numChannels, static_cast<int>(finalSamples.size())};
    ringBuffer.processBlock(numChannels - 1, finalBlock, finalBlock.getNumSamples());

    // Verify the output is [3, 1, 2], meaning the write position wrapped around to the first index.
    const float expectedOutput [3] {3, 1, 2};
    REQUIRE_THAT(ringBuffer.getSample(numChannels - 1, 0), Catch::Matchers::WithinAbs(expectedOutput[0], EPSILON));
    REQUIRE_THAT(ringBuffer.getSample(numChannels - 1, 1), Catch::Matchers::WithinAbs(expectedOutput[1], EPSILON));
    REQUIRE_THAT(ringBuffer.getSample(numChannels - 1, 2), Catch::Matchers::WithinAbs(expectedOutput[2], EPSILON));
}