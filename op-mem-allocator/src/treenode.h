#pragma once
#include <cstddef>

class treenode {
private:
    void* address;
    size_t size;
    bool free;
    treenode* left;
    treenode* right;
    treenode* parent;
public:
    treenode(void* a, size_t s, bool f = true, treenode* p = nullptr);

    void* get_address() const;

    size_t get_size() const;

    bool is_free() const;

    treenode* get_left() const;

    treenode* get_right() const;

    treenode* get_parent() const;

    void set_free(bool f);

    void split();

    void merge();
};