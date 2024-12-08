#include <sys/mman.h>
#include <iostream>
#include <utility>
#include <limits>
#include "memoryallocator.h"
#include "treenode.h"

treenode* root = nullptr;

void* initialize(size_t mem_size) {
    size_t page_size = PAGESIZE;
    if (page_size == -1) {
        std::cerr << "Unable to identify system page size." << std::endl;
        return nullptr;
    }
    if (mem_size % page_size != 0) {
        mem_size = ((mem_size / page_size) + 1) * page_size;
    }
    mem_size = closest_power_of_two(mem_size);
    void* mem_ptr = mmap(nullptr, mem_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (mem_ptr == MAP_FAILED) {
        std::cerr << "Unable to initialize memory of size " << mem_size << "." << std::endl;
        return nullptr;
    }
    root = new treenode(mem_ptr, mem_size);
    return mem_ptr;
}

void* buddy_alloc(size_t size) {
    size_t og = size;
    if (size < PAGESIZE) size = PAGESIZE;
    size = closest_power_of_two(size);
    auto best_fit = find_best_fit(size, root, nullptr, std::numeric_limits<size_t>::max());
    if (best_fit.first) {
        best_fit.first->set_free(false);
        return best_fit.first->get_address();
    } else if (best_fit.second) {
        treenode* curr = best_fit.second;
        while (curr->get_size() >= (2 * size)) {
            curr->set_free(false);
            curr->split();
            curr = curr->get_left();
        }
        return curr->get_address();
    } else {
        std::cerr << "Unable to allocate memory of size " << og << "." << std::endl;
        return nullptr;
    }
}

std::pair<treenode*, treenode*> find_best_fit(size_t size, treenode* curr, treenode* larger, size_t larger_size) {
    if (!curr) return {nullptr, larger};
    if (curr->is_free() && curr->get_size() == size) {
        return {curr, larger};
    } else if (curr->get_size() > size) {
        if (curr->is_free() && curr->get_size() < larger_size) {
            larger = curr;
            larger_size = curr->get_size();
        }
        std::pair<treenode*, treenode*> l = find_best_fit(size, curr->get_left(), larger, larger_size);
        if (l.first) return l;
        std::pair<treenode*, treenode*> r = find_best_fit(size, curr->get_right(), larger, larger_size);
        if (r.first) return r;
        if (l.second->get_size() <= r.second->get_size()) {
            return l;
        } else {
            return r;
        }
    } else {
        return {nullptr, larger};
    }
}

void buddy_dealloc(void* addr) {
    treenode* to_dealloc = find_node(addr, root);
    if (!to_dealloc) {
        std::cerr << "Invalid address " << addr << " for freeing." << std::endl;
        return;
    }
    while (!(to_dealloc->get_left() == nullptr && to_dealloc->get_right() == nullptr)) {
        to_dealloc = to_dealloc->get_left();
    }
    to_dealloc->set_free(true);
    treenode* parent = to_dealloc->get_parent();
    merge_parents(parent);
}

treenode* find_node(void* addr, treenode* curr) {
    if (!curr) return nullptr;
    if (curr->get_address() == addr) {
        return curr;
    }
    size_t start = reinterpret_cast<size_t>(curr->get_address());
    size_t end = start + curr->get_size();
    if (reinterpret_cast<size_t>(addr) < start || reinterpret_cast<size_t>(addr) >= end) {
        return nullptr;
    }
    if (reinterpret_cast<size_t>(addr) < (start + curr->get_size() / 2)) {
        return find_node(addr, curr->get_left());
    } else {
        return find_node(addr, curr->get_right());
    }
}

void merge_parents(treenode* parent) {
    if (!parent) {
        return;
    }
    if (parent->get_left()->is_free() && parent->get_right()->is_free()) {
        parent->merge();
        merge_parents(parent->get_parent());
    } else {
        return;
    }
}

size_t closest_power_of_two(size_t x) {
    if (x == 0) return 0;
    return pow(2, ceil(log2(x)));
}