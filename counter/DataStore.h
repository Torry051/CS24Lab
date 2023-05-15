#ifndef DATASTORE_H
#define DATASTORE_H

#include<string>
#include<iostream>

// Space to implement a separate datastore class, if you choose to do so.
// This can make things simpler by clearly separating functionality.
// The DataStore is in charge of storing pairs in insertion order.



struct Node {
    int count;
    std::string str;
    Node * next;
    Node * last;
    Node():count(0),next(nullptr),last(nullptr){};
    Node(int val,std::string k):count(val),next(nullptr),last(nullptr),str(k){};
};

class DataStore {
    public:
    Node * head;
    Node * tail;
    size_t size;

    public:
    DataStore():head(nullptr),tail(nullptr),size(0){};
    ~DataStore();
    // void increament();
    void insert(int val, std::string k);
    void remove (std::string k,Node*curr);
    void incre(std::string k, int by = 1,Node* curr=nullptr);
    void decre(std::string k, int by = 1,Node* curr=nullptr);
};
#endif