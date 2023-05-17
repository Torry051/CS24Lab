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

int Counter::total() const{
    return table.tot;
}   


Counter::Iterator Counter::begin() const{
    // std::cout << "w: "<<  table._data->head->str << std::endl;
    Iterator result(table._data->head);

    // std::cout << "works" <<std::endl;
    return result;
}

Counter::Iterator Counter::end(){
    // std::cout << "run2. " << table._data->tail->count <<std::endl;
    // std::cout << "running" << std::endl;
    Iterator result;

    // std::cout << "works" <<std::endl;
    return result;
 
}

const std::string& Counter::Iterator::key() const{
    return nod->str;
}

int Counter::Iterator::value() const{
    return nod->count;
}

Counter::Iterator& Counter::Iterator::operator ++ (){
    // std::cout << "run" <<std::endl;
 

    this->nod = this->nod->next;
    return *this;



}

bool    Counter::Iterator::operator == (const Iterator& other) const{
    if(nod == other.nod){
        return true;
    }

    return false;
}

bool    Counter::Iterator::operator != (const Iterator& other) const{
   
    if (nod == other.nod){
        return false;
    }
    
    return true;
}

Counter::Iterator::~Iterator(){

}

