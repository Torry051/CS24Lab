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
    Node * i_next;
    Node * i_last;
    Node():count(0),next(nullptr),last(nullptr),i_next(nullptr),i_last(nullptr){};
    Node(int val,std::string k):count(val),str(k),next(nullptr),last(nullptr),i_next(nullptr),i_last(nullptr){};

};

class DataStore {
    public:
    Node * head;
    Node * tail;
    size_t S;


    public:
    DataStore():head(nullptr),tail(nullptr),S(0){};
    ~DataStore();
    // void increament();
    void insert(int val, std::string k);
    void ins(Node * n);
    void remove (std::string k,Node*curr);
    void incre(std::string k, int by = 1,Node* curr=nullptr);
    void decre(std::string k, int by = 1,Node* curr=nullptr);
};
#endif