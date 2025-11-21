//
// Created by Joe Bristow on 18/11/2025.
//

#include <numeric>
#include "../Source/CircularBuffer.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_all.hpp>

constexpr double EPSILON {1e-9};
constexpr int numChannels {1};
constexpr int currChannel {numChannels - 1};

TEST_CASE("Circular Buffer: Read Sample", "[circularBuffer]")
{
    constexpr int size {2};
    CircularBuffer cb {numChannels, size};

    // Write 1.0f to the first buffer index
    cb.write(currChannel, 1.0f);
    REQUIRE_THAT(cb.read(currChannel, 0), Catch::Matchers::WithinAbs(1.0f, EPSILON));
}

TEST_CASE("Circular Buffer: Write Sample", "[circularBuffer]")
{
    constexpr int size {2};
    CircularBuffer cb {numChannels, size};

    // Write 0.0f and 1.0f to indexes 0 and 1 respectively, filling the buffer.
    cb.write(currChannel, 0.0f);
    cb.write(currChannel, 1.0f);

    // Verify samples were written.
    REQUIRE_THAT(cb.read(currChannel, 0), Catch::Matchers::WithinAbs(0.0f, EPSILON));
    REQUIRE_THAT(cb.read(currChannel, 1), Catch::Matchers::WithinAbs(1.0f, EPSILON));

    // Verify write position wrapped back to 0 after buffer was filled.
    REQUIRE(cb.getWritePosition() == 0);

    // Write 2.0f to buffer, which should be wrapped to the 0th element.
    cb.write(currChannel, 2.0f);

    // Verify buffer contains [2.0f, 1.0f]
    REQUIRE_THAT(cb.read(currChannel, 0), Catch::Matchers::WithinAbs(2.0f, EPSILON));
    REQUIRE_THAT(cb.read(currChannel, 1), Catch::Matchers::WithinAbs(1.0f, EPSILON));

    // Verify write position was incremented correctly to 1 (full loop).
    REQUIRE(cb.getWritePosition() == 1);
}

TEST_CASE("Circular Buffer: Read Out of Bounds Tests", "[circularBuffer]")
{
    constexpr int size {2};
    CircularBuffer cb {numChannels, size};

    // [0.0f, 1.0f]
    cb.write(currChannel, 0.0f);
    cb.write(currChannel, 2.0f);

    // Verify index < 0 is out of bounds (returns 0.0f i.e. silence)
    REQUIRE_THAT(cb.read(currChannel, -2), Catch::Matchers::WithinAbs(0.0f, EPSILON));

    // Verify index > buffer size is out of bounds (returns 0.0f i.e. silence)
    REQUIRE_THAT(cb.read(currChannel, size), Catch::Matchers::WithinAbs(0.0f, EPSILON));
}
