#pragma once
#include <unistd.h>
#include <utility>
#include "treenode.h"

#define PAGESIZE sysconf(_SC_PAGESIZE)

extern treenode* root;

void* initialize(size_t mem_size);

void* buddy_alloc(size_t size);

std::pair<treenode*, treenode*> find_best_fit(size_t size, treenode* curr, treenode* larger, size_t larger_size);

void buddy_dealloc(void* addr);

treenode* find_node(void* addr, treenode* curr);

void merge_parents(treenode* parent);

size_t closest_power_of_two(size_t x);