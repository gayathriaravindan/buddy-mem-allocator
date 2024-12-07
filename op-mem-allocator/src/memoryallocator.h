#pragma once
#include <unistd.h>

#define PAGESIZE sysconf(_SC_PAGESIZE)

void* initialize(size_t mem_size);

void* buddy_alloc(size_t size);

void* buddy_realloc(size_t size);

void buddy_dealloc(void* pointer);

size_t closest_power_of_two(size_t x);