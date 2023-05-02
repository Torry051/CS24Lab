#include "Set.h"
#include <iostream>


Set::Set(){
    mRoot = nullptr;
}

Set::Set(const Set& other){
    if (other.mRoot == nullptr) {
        // std::cout << "running2" << std::endl;
        this->mRoot = nullptr;
        return;
    }
    else if (other.mRoot->leftchild == nullptr && other.mRoot->rightchild == nullptr) {
        // std::cout << "running3" << std::endl;
        this->mRoot = new Node(other.mRoot->element);
    }
    else {
        // std::cout << "running1" << std::endl;
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
    this->mRoot = nullptr;
    return result;
}   

Set::~Set(){
    if (this->mRoot == nullptr) {
        return;
    }
    else {
        // std::cout << "running" << std::endl;
        clear();
    }
}

bool Set::contains(const std::string& value) const {
    if (this->mRoot == nullptr){
        return false;
    }

    if (containh(this->mRoot,value)){
        return true;
    }
    else {
        return false;
    }
}

size_t Set::count() const{
    return counth(this->mRoot,0);
}

void debug(){
    return;
}

size_t Set::insert(const std::string& value) {
    if (contains(value)){
        return 0;
    }
    if (mRoot == nullptr){
        Node * root = new Node(value);
        mRoot = root;
        return 1;
    }
    size_t s = inserth(this->mRoot, value);
    
    return 1;
}

const std::string& Set::lookup(size_t n) const{
    if (n >= count()){
        throw std::out_of_range("out of range!");
    }
    return lookh(mRoot,n);
}

void Set::print() const {
    if (this->mRoot == nullptr){
        std::cout << "-" << std::endl;
        return;
    }
    std::string str = printh(this->mRoot);
    std::cout << str;
}

size_t Set::remove(const std::string& value){
    if (!contains(value)){
        return 0;
    } 
    removeh(mRoot,value);
    return 1;
}

