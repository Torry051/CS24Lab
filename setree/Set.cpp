#include "Set.h"
#include <iostream>


Set::Set(){
    mRoot = nullptr;
}

Set::Set(const Set& other):mRoot(nullptr){
    if (other.mRoot == nullptr) {
        std::cout << "running2" << std::endl;
        return;
    }
    else if (other.mRoot->leftchild == nullptr && other.mRoot->rightchild == nullptr) {
        std::cout << "running3" << std::endl;
        this->mRoot = new Node(other.mRoot->element);
    }
    else {
        std::cout << "running1" << std::endl;
        this->mRoot = Conhelper(other.mRoot);
    }
}


Set::Set(Set&& other){
    // std::cout << "using" << std::endl;
    this->mRoot = other.mRoot;
    other.mRoot = nullptr;
}

size_t Set::clear() {
    size_t result = clearh(mRoot,0);
    mRoot = nullptr;
    return result;

}   

Set::~Set(){
    if (mRoot == nullptr) {
        return;
    }
    else {
        // std::cout << "running" << std::endl;
        clear();
    }
}

bool Set::contains(const std::string& value) const {
    if (mRoot == nullptr){
        return false;
    }

    if (containh(mRoot,value)){
        return true;
    }
    else {
        return false;
    }
}

size_t Set::count() const{
    return counth(mRoot,0);
}

void debug(){
    return;
}

size_t Set::insert(const std::string& value) {
    if (contains(value)){
        return 0;
    }
    size_t s = inserth(mRoot, value);
    if (s== 0) {
        std::cout << "wrong"<<std::endl;
    }
    return 1;
}

const std::string& Set::lookup(size_t n) const{
    if (n >= count()){
        throw std::out_of_range("out of range!");
    }
    return lookh(mRoot,n);
}

void Set::print() const {
    if (mRoot == nullptr){
        std::cout << "-" << std::endl;
        return;
    }
    std::string str = printh(mRoot);
    std::cout << str;
}

size_t Set::remove(const std::string& value){
    if (!contains(value)){
        return 0;
    } 
    removeh(mRoot,value);
    return 1;
}

