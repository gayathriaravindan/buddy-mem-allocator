#include <iostream>
#include "treenode.h"

treenode::treenode(void *a, size_t s, bool f, treenode* p)
: address(a), size(s), free(f), left(nullptr), right(nullptr), parent(p) {}

void* treenode::get_address() const {
    return address;
}

size_t treenode::get_size() const {
    return size;
}

bool treenode::is_free() const {
    return free;
}

bool treenode::is_leaf() const {
    return left == nullptr && right == nullptr;
}

void treenode::split() {
    size_t child_size = size / 2;
    left = new treenode(address, child_size, true, this);
    right = new treenode(static_cast<char*>(address) + child_size, child_size, true, this);
    free = false;
}

void treenode::merge() {
    delete left;
    delete right;
    left = nullptr;
    right = nullptr;
    free = true;
}
