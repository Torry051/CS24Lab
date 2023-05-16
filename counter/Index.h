#ifndef INDEX_H
#define INDEX_H

#include<string>
#include "DataStore.h"

// Space to implement a separate index class, if you choose to do so.
// This can make things simpler by clearly separating functionality.
// The Index is in charge of getting pairs from the DataStore by key.
struct item{
    std::string _key;
    Node * node;
    item():node(nullptr){};
    ~item(){
        node = nullptr;
    }
};


class Index{
    public:
    size_t size;
    item * arr;
    size_t capacity;
    DataStore  * _data;
    int tot;

    public:
    Index();
    Index(size_t val);
    ~Index();
    void expand();
    void insert(std::string key, int count);
    size_t idx(std::string) const;
    int search(std::string k) const;
    void remove(std::string k);
    void increment(std::string k, int by = 1);
    void decrement(std::string k, int by = 1);
};

#endif
