#include "Counter.h"

// Counter Member Functions
Counter::Counter(){
    size = 0;
}   

Counter::~Counter(){

}

void Counter::set(const std::string& key, int count){
    table.insert(key,count);
    size += 1;
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
}

void Counter::dec(const std::string& key, int by){
    table.decrement(key,by);
}

size_t Counter::count() const{
    return size;
}


Counter::Iterator Counter::begin() const{
    Iterator result(table._data->head);
    return result;
}

Counter::Iterator Counter::end() const{
    Iterator result(table._data->tail);
    return result;
}

const std::string& Counter::Iterator::key() const{
    return nod->str;
}

int Counter::Iterator::value() const{
    return nod->count;
}

Counter::Iterator& Counter::Iterator::operator ++ (){
    static Iterator result(nod->next);
    return result;
}

bool    Counter::Iterator::operator == (const Iterator& other) const{
    if(nod == other.nod){
        return true;
    }
    return false;
}

bool     Counter::Iterator::operator != (const Iterator& other) const{
    if (*this == other){
        return false;
    }
    return true;
}