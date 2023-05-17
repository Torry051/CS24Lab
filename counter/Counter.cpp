#include "Counter.h"

// Counter Member Functions
// Counter::Counter(){
//     Index result;
//     table = result;
//     size = 0;
// }   

Counter::~Counter(){

}

void Counter::set(const std::string& key, int count){
    table.insert(key,count);
    size = table.size;
}

int Counter::get(const std::string& key) const{
    int result = table.search(key);
    return result;
}

void Counter::del(const std::string& key){
    table.remove(key);
}

void Counter::inc(const std::string& key, int by){
    table.increment(key, by);
    size = table.size;
}

void Counter::dec(const std::string& key, int by){
    table.decrement(key,by);
}

size_t Counter::count() const{
    return size;
}

// int Counter::total() const{
//     return table.tot;
// }   


Counter::Iterator Counter::begin() const{
    // std::cout << "w: "<<  table._data->head->str << std::endl;
    Iterator result(table._data->head);

    // std::cout << "works" <<std::endl;
    return result;
}

Counter::Iterator Counter::end(){
    // std::cout << "run2. " << table._data->tail->count <<std::endl;
    // if (table._data->tail!=nullptr){
    //     std::cout << size <<std::endl;
    // }
    if (e==nullptr){
        e = table._data->tail;
        static Iterator result(e);
        std::cout << "run2. " << result.nod->count <<std::endl;
        return result;
    }
    else{
        std::cout << "run3 " << e->count <<std::endl;
        static Iterator result(e);

        std::cout << "run2. " << result.nod->count <<std::endl;
        return result;
    }

 
}

const std::string& Counter::Iterator::key() const{
    return nod->str;
}

int Counter::Iterator::value() const{
    return nod->count;
}

Counter::Iterator& Counter::Iterator::operator ++ (){
    // std::cout << "run" <<std::endl;
    // std::cout << nod->next->count <<std::endl;
    static Iterator result(nod->next);
    // std::cout << result.nod->count <<std::endl;
    // std::cout << "run" <<std::endl;
    // if (result.nod == nullptr){
    //     std::cout << "yes" <<std::endl;
    // }
    return result;
}

bool    Counter::Iterator::operator == (const Iterator& other) const{
    if(nod == other.nod){
        return true;
    }

    return false;
}

bool    Counter::Iterator::operator != (const Iterator& other) const{
    if (*this == other){
        return false;
    }
    return true;
}

Counter::Iterator::~Iterator(){
  
}

