#include <iostream>
#include <unistd.h>
#include <vector>
// #include <benchmark/benchmark.h>
#include "memoryallocator.h"

void initialize_tests();
void buddy_alloc_tests();
void buddy_dealloc_tests();

int main() {
    //initialize_tests();
}

void initialize_tests() {
    std::vector<size_t> test = {
            0, //0 bytes, should return error
            1,
            128,
            1024, //1 KB
            16384, //1 Page (on dev system)
            20000,
            32768,
            50000,
            123456,
            1048576, //1 MB
            1073741824, //1 GB
            2147483648, //2 GB
            static_cast<size_t>(-1) //max value of size_t, should return error (will overflow to 0)
    };

    for (size_t size : test) {
        std::cout << "size: " << size << "...";
        if (initialize(size)) {
            std::cout << "worked!" << std::endl;
        } else {
            std::cout << "error!" << std::endl;
        }
    }
}

void buddy_alloc_tests() {

}

void buddy_dealloc_tests() {

}

