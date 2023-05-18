#include "Index.h"

// Index Member Functions




Index::Index(){
    arr = new item[100];
    size = 0;
    capacity = 100;
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
    result = result % (capacity);
    return result;
}

void Index::expand(std::string k, int c){
    // std::cout << "running expand" <<std::endl;
    // size_t j = capacity;
    capacity = capacity * capacity;
    item * new_arr = new item[capacity];
    _data->insert(c,k);

    Node * curr = _data->head;
    
    // for (size_t i = 0; i< j; i++){
    while(curr !=nullptr){
        // if (arr[i].node!=nullptr){
            // std::cout<< arr[i]._key <<std::endl;
            size_t index = idx(curr->str);
            if (new_arr[index].node==nullptr){
                new_arr[index].node = curr;
                new_arr[index]._key = curr->str;
                // if (arr[i]._key == "french hens"){
                //     std::cout << "Index1: " << index << " " << capacity<< std::endl;
                // }
            }
            else{
                int n = 1;
                while(new_arr[index].node != nullptr){
                    index = index + n*n;
                    if (index >= capacity){
                        index = index % capacity;
                    }

                }
                new_arr[index].node = curr;
                new_arr[index]._key = curr->str;
                n=n+1;
                // if (arr[i]._key == "french hens"){
                //     std::cout << "Index2: " << index << std::endl;
                }
            // }
        // }
    }
    delete [] arr;
    arr = new_arr;
    new_arr = nullptr;
    this->size += 1;
}

void Index::insert(std::string key, int count){
    // std::cout << "running set: " << key << " "<<count <<std::endl;
    
    // std::cout << "running"  << key << " " << count<<std::endl;
    if(size > (capacity/4)){
        expand(key,count);
        // std::cout << "expand:" << capacity <<std::endl;
        return;
    }
    size_t index = idx(key);
    // std::cout << "index: " << index  << "capacity: " << capacity<<std::endl;

    if(arr[index].node == nullptr){
        _data->insert(count,key);
        arr[index].node = _data->tail;
        arr[index]._key = key;
        // std::cout << index <<" " << key<<  " " << count<<std::endl;
        tot += count;
        this->size+=1;
    }
    else if(arr[index]._key == key){
        tot = tot - arr[index].node->count;
        arr[index].node->count = count;
        tot = tot + count;
    }
    else {
        int n = 1;
        while(arr[index].node!=nullptr){
            index = index + n*n;
            
            if(index >= capacity){
                index = index % capacity;
            }

            if(arr[index]._key == key){
                break;
            }
            n= n + 1;
        }
        if (arr[index]._key == key){
            tot =tot -arr[index].node->count;
            arr[index].node->count = count;
            tot = tot + count;
        }
        else {
            _data->insert(count,key);
            arr[index].node = _data->tail;
            arr[index]._key = key;
            tot += count;
            this->size +=1;
        }
    }
}

int Index::search(std::string k) const{
    size_t index = idx(k);
    // std::cout << index << std::endl;
    if (arr[index].node == nullptr){
        // std::cout << index <<" " <<capacity<<std::endl;
        return 0;
    }
    else if (arr[index]._key == k){
        return arr[index].node->count;
    }
    else {
        int n = 1;
        while(arr[index].node!=nullptr){
            // std::cout << index << std::endl;
            index = index + n*n;
            if (index >= capacity){
                index = index % capacity;
            }

            if (arr[index]._key == k){
                return arr[index].node->count;
            }
            n = n+1;
        }
        // std::cout << "index" << std::endl;
        return 0;
    }
    std::cout << "wrong" <<std::endl;
    return 999;
}

void Index::remove(std::string k) {
    // std::cout << "rem: "<< k <<std::endl;
    int count = 0;
    size_t index = idx(k);
    if (arr[index].node == nullptr){
        std::cout << "wrong: "<< index <<std::endl;
        return;
    }
    else if (arr[index]._key == k){
        Node * curr = arr[index].node;
        count = curr->count;
        _data->remove(k,curr);
        size= size -1;
        arr[index]._key = "";
        tot = tot - count;
    }
    else{
        int n = 1;
        while(arr[index].node!=nullptr){
            index = index + n*n;
            if(index>= capacity){
                index = index % capacity;
            }
            if (arr[index]._key == k){
                Node * curr = arr[index].node;
                count = curr->count;
                _data->remove(k,curr);
                size= size -1;
                arr[index]._key = "";
                tot = tot - count;
                return;
            } 
            n=n+1;
        }
        std::cout << "wrong1: "<< index <<std::endl;
        std::cout << capacity << arr[13]._key <<std::endl;
    }
}

void Index::increment(std::string k, int by){
    // std::cout << "running inc" << k<< ": "<< by<<std::endl;
    size_t index = idx(k);
    // std::cout << "inside : "<<size <<std::endl;
    if (arr[index]._key == k){
        _data->incre(k,by,arr[index].node);
        tot = tot + by;
    }
    else if (arr[index].node == nullptr){
        insert(k,by);
    }
    else {
        int n = 1;
        while(arr[index].node!=nullptr){
            index = index + n*n;
            if (index >= capacity){
                index = index % capacity;
            }

            if (arr[index]._key == k){
                _data->incre(k,by,arr[index].node);
                tot = tot+by;
                return;
            }
            n=n+1;
        }
        // std::cout << "inside3 : "<<size <<std::endl;
        // int val = 0;
        // for(size_t i =0; i<k.length();i++){
        //     val += k[i];
        // }
  
        insert(k, by);
     
    }
}

void Index::decrement(std::string k, int by){
    // std::cout << "running dec: " << k << " " << by <<std::endl;
    
    size_t index = idx(k);
    if (arr[index]._key == k){
        _data->decre(k,by,arr[index].node);
        tot = tot -by;
    }
    else if (arr[index].node == nullptr){

        // std::cout << "using insert" <<std::endl;
        insert(k,-by);

    }
    else {
        int n = 1;
        while(arr[index].node!=nullptr){
            index = index + n*n;
            if (index >= capacity){
                index = index % capacity;
            }


            if (arr[index]._key == k){
                _data->decre(k,by,arr[index].node);
                tot = tot -by;
                return;
            }
            n=n+1;
        }


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