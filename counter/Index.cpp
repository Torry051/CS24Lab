#include "Index.h"

// Index Member Functions




Index::Index(){
    arr = new item[10];
    size = 0;
    capacity = 10;
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
    result = result % (capacity+1);
    return result;
}

void Index::expand(){
    capacity = 2 * capacity;
    item * new_arr = new item[capacity];
    
    for (size_t i = 0; i< (capacity/2); i++){
        if (arr[i].node!=nullptr){
            size_t index = idx(arr[i]._key);
            new_arr[index].node = arr[i].node;
            new_arr[index]._key = arr[i]._key;
        }
    }
    delete [] arr;
    arr = new_arr;
    new_arr = nullptr;
}

void Index::insert(std::string key, int count){
    if(size >= (capacity/2)){
        expand();
    }
    size_t index = idx(key);
    int ind = index;
    if(arr[index].node == nullptr){
        _data->insert(count,key);
        arr[ind].node = _data->tail;
        arr[ind]._key = key;
        tot += count;
        size += 1;
        // std::cout << key<<  " " << count<<std::endl;
    }
    else if (arr[ind]._key == key){//
        arr[ind].node->count = count;//
        tot = tot - arr[ind].node->count + count;
    }//
    else {
        while(arr[ind].node!=nullptr || arr[ind]._key == key){
            if(index < capacity-1){
                index+=1;
            }
            else{
                index = 0;
            } 
        }
        if (arr[ind]._key == key){
            tot = tot - arr[ind].node->count + count;
            arr[ind].node->count = count;
            
        }
        else{
            _data->insert(count,key);
            arr[ind].node = _data->tail;
            arr[ind]._key = key;
            tot += count;
            size += 1;
        }
    }
}

int Index::search(std::string k) const{
    size_t index = idx(k);
    int ind = index;
    // std::cout << index << std::endl;
    if (arr[ind].node == nullptr){
        return 0;
    }
    else if (arr[ind]._key == k){
        return arr[ind].node->count;
    }
    else {
        while(arr[ind].node!=nullptr){
            // std::cout << index << std::endl;
            if(index < capacity-1){
                index+=1;
            }
            else{
                index = 0;
            } 

            if (arr[ind]._key == k){
                return arr[ind].node->count;
            }
        }
        // std::cout << "index" << std::endl;
        return 0;
    }
    std::cout << "wrong" <<std::endl;
    return 999;
}

void Index::remove(std::string k) {
    int count = 0;
    size_t index = idx(k);
    if (arr[index].node == nullptr){
        return;
    }
    else if (arr[index]._key == k){
        Node * curr = arr[index].node;
        count = curr->count;
        _data->remove(k,curr);
        size= size -1;
        arr[index]._key = "";
    }
    else{
        while(arr[index].node!=nullptr){
            if(index < capacity-1){
                index+=1;
            }
            else{
                index = 0;
            }
            if (arr[index]._key == k){
                Node * curr = arr[index].node;
                count = curr->count;
                _data->remove(k,curr);
                size= size -1;
                arr[index]._key = "";
            } 
        }
    }
    tot = tot - count;
}

void Index::increment(std::string k, int by){
    size_t index = idx(k);
    if (arr[index]._key == k){
        _data->incre(k,by,arr[index].node);
        tot = tot + by;
    }
    else if (arr[index].node == nullptr){
        // int val = 0;
        // for(size_t i =0; i<k.length();i++){
        //     val += k[i];
        // }

        insert(k,by);
    }
    else {
        while(arr[index].node!=nullptr){
            if (index < (capacity -1)){
                index = index +1;
            }
            else{
                index = 0;
            }

            if (arr[index]._key == k){
                _data->incre(k,by,arr[index].node);
                tot = tot+by;
            }
        }
        // int val = 0;
        // for(size_t i =0; i<k.length();i++){
        //     val += k[i];
        // }

        insert(k,+by);
    }
}

void Index::decrement(std::string k, int by){
    size_t index = idx(k);
    if (arr[index]._key == k){
        _data->decre(k,by,arr[index].node);
        tot = tot -by;
    }
    else if (arr[index].node == nullptr){
        // int val = 0;
        // for(size_t i =0; i<k.length();i++){
        //     val += k[i];
        // }

        insert(k,-by);
    }
    else {
        while(arr[index].node!=nullptr){
            if (index < (capacity -1)){
                index = index +1;
            }
            else{
                index = 0;
            }

            if (arr[index]._key == k){
                _data->decre(k,by,arr[index].node);
                tot = tot -by;
            }
        }
        // int val = 0;
        // for(size_t i =0; i<k.length();i++){
        //     val += k[i];
        // }

        insert(k,-by);
    }
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