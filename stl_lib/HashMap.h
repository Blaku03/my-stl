#ifndef MY_STL_HASHMAP_H
#define MY_STL_HASHMAP_H

#include "LinkedList.hxx"
#include "vstring.h"
#include "vector.hxx"
#include "pair.hxx"

using my_stl::LinkedList;
using my_stl::vstring;
using my_stl::vector;
using my_stl::pair;

class HashMap {

    int sizeOfTable = 10000000;
    int numberOfElements = 0;
    vector<LinkedList<pair<vstring, int>>> main_table;

public:

    HashMap() : main_table(sizeOfTable) {}

    ~HashMap() = default;

    [[nodiscard]] int hash(vstring key) const;

    void insert(const vstring &key, int value);

    int get(const vstring &key);

    void remove(const vstring &key);

    bool contains(const vstring &key);

    [[nodiscard]] int size() const;
};


#endif //MY_STL_HASHMAP_H
