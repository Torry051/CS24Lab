#include "DataStore.h"

// DataStore Member Functions

void DataStore::insert(int val,std::string k){
    // std::cout <<"in: " <<Size << std::endl;
    Node * new_node = new Node(val,k);
    if(S == 0){
        head = new_node;
        tail = new_node;
        S = 1;

    }
    else{
        Node * curr = tail;
        tail = new_node;
        new_node->last = curr;
        curr->next = tail;
        S += 1;

    }
    // std::cout <<"in: " <<S << std::endl;
    
}

void DataStore::ins(Node * n){
    if(S==0){
        head = n;
        tail = n;
        S =1;
    }
    else{
        // std::cout << "inside: " << D->tail->str << std::endl;
        Node * curr = tail;
        tail = n;
        tail->i_last = curr;
        curr->i_next = tail;
        S+=1;
    }
}


void DataStore::remove(std::string k,Node* curr){
    if(curr==head && curr==tail){
            curr->str="";
            delete curr;
            head = nullptr;
            tail = nullptr;
    }
    else if (curr == head){
            curr->str = "";
            Node * Next = curr->next;
            delete curr;
            Next->last = nullptr;
            head = Next;
    }
    else if (curr == tail){
            curr->str = "";
            Node * Last = curr->last;
            delete curr;
            Last->next = nullptr;
            tail = Last;
    }
    else {
            curr->str = "";
            Node * Last = curr->last;
            Node * Next = curr->next;
            delete curr;
            Last->next = Next;
            Next->last = Last;
    }
    S = S -1;
}

void DataStore::incre(std::string k, int by,Node * curr){
    curr->count = curr->count + by;
}

void DataStore::decre(std::string k, int by ,Node* curr){
    curr->count = curr->count -by;
}

DataStore::~DataStore(){

    // std::cout << "desc" <<std::endl;
    // std::cout << "running2" <<std::endl;
    if (head == tail && head == nullptr){
        // std::cout << "running231" <<std::endl;
        return;
    }
    else if (head->str ==""){
        // std::cout << "123" <<std::endl;
        return;
    }
    else if (head == tail && tail != nullptr){
        
        head->str = "";
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else{
        // std::cout << "321" <<std::endl;
        Node * curr = head;
        Node * temp = curr->next;
        // std::cout << "running231" <<std::endl;
        while(curr != nullptr){
            if(curr == nullptr){
                break;
            }
            // std::cout << "deleting: "<< curr->str << ": "<< curr->count <<std::endl;
            // std::cout << "running31" <<std::endl;
            curr->str = "";
            delete curr;
            curr =nullptr;
            if(temp == nullptr){
                // std::cout << "running21" <<std::endl;
                tail = nullptr;
                head = nullptr;
                break;
            }
            // std::cout << "running13" <<std::endl;
            curr = temp;
            temp = curr->next;
        }
    }
    

    // std::cout << "running231" <<std::endl;

}
