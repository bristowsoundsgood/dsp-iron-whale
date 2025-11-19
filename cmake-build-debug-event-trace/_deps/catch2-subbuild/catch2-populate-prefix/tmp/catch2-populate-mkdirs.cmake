# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/Users/joebristow/Desktop/CS/Software Engineering/Mid-Level/DSP/Projects/dsp-iron-whale/cmake-build-debug-event-trace/_deps/catch2-src")
  file(MAKE_DIRECTORY "/Users/joebristow/Desktop/CS/Software Engineering/Mid-Level/DSP/Projects/dsp-iron-whale/cmake-build-debug-event-trace/_deps/catch2-src")
endif()
file(MAKE_DIRECTORY
  "/Users/joebristow/Desktop/CS/Software Engineering/Mid-Level/DSP/Projects/dsp-iron-whale/cmake-build-debug-event-trace/_deps/catch2-build"
  "/Users/joebristow/Desktop/CS/Software Engineering/Mid-Level/DSP/Projects/dsp-iron-whale/cmake-build-debug-event-trace/_deps/catch2-subbuild/catch2-populate-prefix"
  "/Users/joebristow/Desktop/CS/Software Engineering/Mid-Level/DSP/Projects/dsp-iron-whale/cmake-build-debug-event-trace/_deps/catch2-subbuild/catch2-populate-prefix/tmp"
  "/Users/joebristow/Desktop/CS/Software Engineering/Mid-Level/DSP/Projects/dsp-iron-whale/cmake-build-debug-event-trace/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp"
  "/Users/joebristow/Desktop/CS/Software Engineering/Mid-Level/DSP/Projects/dsp-iron-whale/cmake-build-debug-event-trace/_deps/catch2-subbuild/catch2-populate-prefix/src"
  "/Users/joebristow/Desktop/CS/Software Engineering/Mid-Level/DSP/Projects/dsp-iron-whale/cmake-build-debug-event-trace/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/joebristow/Desktop/CS/Software Engineering/Mid-Level/DSP/Projects/dsp-iron-whale/cmake-build-debug-event-trace/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/joebristow/Desktop/CS/Software Engineering/Mid-Level/DSP/Projects/dsp-iron-whale/cmake-build-debug-event-trace/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
