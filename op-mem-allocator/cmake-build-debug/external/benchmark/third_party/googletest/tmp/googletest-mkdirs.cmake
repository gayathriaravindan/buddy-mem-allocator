# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/gayathriaravindan/Desktop/Portfolio/CPP/buddy-mem-allocator/op-mem-allocator/external/benchmark/googletest"
  "/Users/gayathriaravindan/Desktop/Portfolio/CPP/buddy-mem-allocator/op-mem-allocator/cmake-build-debug/external/benchmark/third_party/googletest/build"
  "/Users/gayathriaravindan/Desktop/Portfolio/CPP/buddy-mem-allocator/op-mem-allocator/cmake-build-debug/external/benchmark/third_party/googletest"
  "/Users/gayathriaravindan/Desktop/Portfolio/CPP/buddy-mem-allocator/op-mem-allocator/cmake-build-debug/external/benchmark/third_party/googletest/tmp"
  "/Users/gayathriaravindan/Desktop/Portfolio/CPP/buddy-mem-allocator/op-mem-allocator/cmake-build-debug/external/benchmark/third_party/googletest/src/googletest-stamp"
  "/Users/gayathriaravindan/Desktop/Portfolio/CPP/buddy-mem-allocator/op-mem-allocator/cmake-build-debug/external/benchmark/third_party/googletest/download"
  "/Users/gayathriaravindan/Desktop/Portfolio/CPP/buddy-mem-allocator/op-mem-allocator/cmake-build-debug/external/benchmark/third_party/googletest/src/googletest-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/gayathriaravindan/Desktop/Portfolio/CPP/buddy-mem-allocator/op-mem-allocator/cmake-build-debug/external/benchmark/third_party/googletest/src/googletest-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/gayathriaravindan/Desktop/Portfolio/CPP/buddy-mem-allocator/op-mem-allocator/cmake-build-debug/external/benchmark/third_party/googletest/src/googletest-stamp${cfgdir}") # cfgdir has leading slash
endif()
