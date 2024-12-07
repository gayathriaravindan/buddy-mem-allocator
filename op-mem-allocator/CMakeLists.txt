cmake_minimum_required(VERSION 3.28)

#project name and version
project(Multithreaded_Buddy_Memory_Allocator VERSION 1.0)

#C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add Google Benchmark and Google Test
set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON)
add_subdirectory(external/benchmark)

#packages
find_package(Threads REQUIRED)

#executable
add_executable(MemoryAllocator
        src/main.cpp
        src/memoryallocator.cpp
        src/memoryallocator.h
        src/treenode.cpp
        src/treenode.h
)

#link libraries
target_link_libraries(MemoryAllocator
        benchmark::benchmark
        Threads::Threads
)