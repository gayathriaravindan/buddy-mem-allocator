# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/gayathriaravindan/Desktop/Portfolio/CPP/op-mem-allocator/cmake-build-debug/external/benchmark/third_party/googletest/src"
  "/Users/gayathriaravindan/Desktop/Portfolio/CPP/op-mem-allocator/cmake-build-debug/external/benchmark/third_party/googletest/build"
  "/Users/gayathriaravindan/Desktop/Portfolio/CPP/op-mem-allocator/cmake-build-debug/external/benchmark/third_party/googletest"
  "/Users/gayathriaravindan/Desktop/Portfolio/CPP/op-mem-allocator/cmake-build-debug/external/benchmark/third_party/googletest/tmp"
  "/Users/gayathriaravindan/Desktop/Portfolio/CPP/op-mem-allocator/cmake-build-debug/external/benchmark/third_party/googletest/stamp"
  "/Users/gayathriaravindan/Desktop/Portfolio/CPP/op-mem-allocator/cmake-build-debug/external/benchmark/third_party/googletest/download"
  "/Users/gayathriaravindan/Desktop/Portfolio/CPP/op-mem-allocator/cmake-build-debug/external/benchmark/third_party/googletest/stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/gayathriaravindan/Desktop/Portfolio/CPP/op-mem-allocator/cmake-build-debug/external/benchmark/third_party/googletest/stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/gayathriaravindan/Desktop/Portfolio/CPP/op-mem-allocator/cmake-build-debug/external/benchmark/third_party/googletest/stamp${cfgdir}") # cfgdir has leading slash
endif()
