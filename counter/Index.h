#ifndef INDEX_H
#define INDEX_H

#include<string>
#include "DataStore.h"

// Space to implement a separate index class, if you choose to do so.
// This can make things simpler by clearly separating functionality.
// The Index is in charge of getting pairs from the DataStore by key.
struct item{
    std::string _key;
    DataStore * item_D;
    item(){
        _key = "";
        item_D = new DataStore;
    };
    ~item(){
        // std::cout << "running" << std::endl;
        item_D->head=nullptr;
        item_D->tail=nullptr;
        delete item_D;
        
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
    void insert(std::string key, int count);
    size_t idx(std::string) const;
    int search(std::string k) const;
    void remove(std::string k);
    void increment(std::string k, int by = 1);
    void decrement(std::string k, int by = 1);
};

#endif
