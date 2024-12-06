#pragma once
#include <unistd.h>

//definitions
#define PAGESIZE sysconf(_SC_PAGESIZE)

void* initialize(size_t mem_size);
void* buddy_alloc(size_t size);
void* buddy_realloc(size_t size);
void buddy_dealloc(void* pointer);