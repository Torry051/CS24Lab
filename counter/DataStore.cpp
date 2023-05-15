#include "DataStore.h"

// DataStore Member Functions

void DataStore::insert(int val,std::string k){
    Node * new_node = new Node(val,k);
    if(size == 0){
        head = new_node;
        tail = new_node;
        size = 1;

    }
    else{
        Node * curr = tail;
        tail = new_node;
        new_node->last = curr;
        curr->next = tail;
        size += 1;

    }
    
}


void DataStore::remove(std::string k,Node* curr){
    if(curr==head && curr==tail){
            delete curr;
            head = nullptr;
            tail = nullptr;
    }
    else if (curr == head){
            Node * Next = curr->next;
            delete curr;
            Next->last = nullptr;
            head = Next;
    }
    else if (curr == tail){
            Node * Last = curr->last;
            delete curr;
            Last->next = nullptr;
            tail = Last;
    }
    else {
            Node * Last = curr->last;
            Node * Next = curr->next;
            delete curr;
            Last->next = Next;
            Next->last = Last;
    }
    size = size -1;
}

void DataStore::incre(std::string k, int by,Node * curr){
    curr->count = curr->count + by;
}

void DataStore::decre(std::string k, int by ,Node* curr){
    curr->count = curr->count -by;
}

DataStore::~DataStore(){
    
    if (head == tail && head == nullptr){
        return;
    }
    else if (head == tail && tail != nullptr){
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else{
        Node * curr = head;
        Node * temp = head->next;
        while(curr != nullptr){
            delete curr;
            if(temp == nullptr){
                tail = nullptr;
                head = nullptr;
                break;
            }
            curr = temp;
            temp = curr->next;
        }
    }

}
