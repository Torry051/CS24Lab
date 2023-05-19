#include "Index.h"

// Index Member Functions




Index::Index(){
    arr = new item[1000];
    size = 0;
    capacity = 1000;
    _data = new DataStore;
    tot = 0;
}

Index::Index(size_t val){
    arr = new item[val];
    size = 0;
    capacity = val;
    _data = new DataStore;
    tot = 0;
}

size_t Index::idx(std::string str) const{
    size_t result=0;
    for (size_t i= 0;i<str.length(); i++){
        result += str[i];
    }
    result = result % capacity;
    return result;
}


void Index::insert(std::string key, int count){
    // std::cout << "running"  << key << " " << count<<std::endl;
    size_t index = idx(key);

    if(arr[index].item_D->head == nullptr){
       
        _data->insert(count,key);
        // std::cout << "running: " << key << std::endl;
        arr[index].item_D->ins(_data->tail);
        
        arr[index]._key = key;
        // std::cout << index <<" " << key<<  " " << count<<std::endl;
        tot += count;
        this->size+=1;
    }
    else if (arr[index]._key == key){
        // std::cout << "running: " << key << std::endl;
        tot = tot - arr[index].item_D->head->count;
        arr[index].item_D->head->count = count;
        tot = tot + count;
    }
    else{
        Node * curr = arr[index].item_D->head;
        while (curr != nullptr){
            if (curr->str == key){
                tot = tot - curr->count;
                curr->count = count;
                tot = tot + count;
                return;
            }
            curr = curr->i_next;
        }
        // if (curr == nullptr){
        _data->insert(count,key);

        arr[index].item_D->ins(_data->tail);
        tot = tot + count;
        size = size + 1;
        // }
        // else{
        //     tot = tot - curr->count;
        //     curr->count = count;
        //     tot = tot + count;
        // }
     }


}

int Index::search(std::string k) const{
    size_t index = idx(k);
    // std::cout << index << std::endl;
    if (arr[index].item_D->head== nullptr){
        // std::cout << index <<" " <<capacity<<std::endl;
        return 0;
    }
    else if (arr[index]._key == k){
        return arr[index].item_D->head->count;
    }
    else {
        Node * curr = arr[index].item_D->head;
        while (curr != nullptr){
            if (curr->str == k){
                return curr->count;
                // break;
            }
            curr= curr->i_next;
        }

        // if (curr != nullptr){
            // return curr->count;
        // }
        return 0;
    }
    std::cout << "wrong" <<std::endl;
    return 999;
}

void Index::remove(std::string k) {
  
    size_t index = idx(k);
    if (arr[index].item_D->head == nullptr){
        std::cout << "wrong: "<< index <<std::endl;
        return;
    }
    else if (arr[index]._key == k){
        Node * curr = arr[index].item_D->head;
        
        if (curr->i_next == nullptr){
            arr[index].item_D->head = nullptr;
            arr[index].item_D->tail = nullptr;
            arr[index]._key = "";
            arr[index].item_D->S = 0;

        }
        else{
            arr[index].item_D->head = curr->i_next;
            arr[index].item_D->head->i_last = nullptr;
            arr[index]._key = curr->i_next->str;


            arr[index].item_D->S += -1;
        }
        
        size = size -1;
        tot = tot - curr->count;
        _data->remove(k,curr); 
    }
    else{
        Node * curr = arr[index].item_D->head;
        while(curr!=nullptr){
            if(curr->str == k){
                size = size -1;
                tot = tot - curr->count;
                if (curr->i_next == nullptr){
                    Node * temp = curr->i_last;
                    temp->i_next = nullptr;
                    arr[index].item_D->tail = temp;
                    arr[index].item_D->S += -1;
                }
                else{
                    Node * temp = curr->i_last;
                    Node * n = curr->i_next;
                    temp->i_next = n;
                    n->i_last = temp;
                    arr[index].item_D->S += -1;
                }
                _data->remove(k,curr);
                return;
            }
            curr = curr->i_next;
        }
        std::cout << "wrong1: "<< index <<std::endl;
        // std::cout << capacity << arr[13]._key <<std::endl;
    }
}

void Index::increment(std::string k, int by){
    // std::cout << "running inc" << k<< ": "<< by<<std::endl;
    size_t index = idx(k);
    // std::cout << "inside : "<<size <<std::endl;
    if(arr[index]._key==k){
        _data->incre(k,by,arr[index].item_D->head);
        tot = tot + by;
    }
    else if (arr[index].item_D->head==nullptr){
        // std::cout << "yes" <<std::endl;
        insert(k,by);
        // arr[index].item_D->ins(_data->tail);
    }
    else{
        Node * curr = arr[index].item_D->head;
        while (curr != nullptr){
            if(curr->str == k){
                 _data->incre(k,by,curr);
                 tot = tot + by;
                 return;
            }
            curr = curr->i_next;
        }
        
        insert(k,by);
        // arr[index].item_D->ins(_data->tail);
    }

}

void Index::decrement(std::string k, int by){
    // std::cout << "running dec: " << k << " " << by <<std::endl;
    increment(k,-by);
}

Index::~Index(){
    // delete [] arr;
    // arr = nullptr;
    delete _data;
    // std::cout << "working" << std::endl;
    // for (size_t i = 0; i<capacity;i++){
    //     arr[i].node = nullptr;
    // }
    delete [] arr;
    arr = nullptr;

}