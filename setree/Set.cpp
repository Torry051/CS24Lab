#include "Set.h"
#include <iostream>


Set::Set(){
    mRoot = nullptr;
}

Set::Set(const Set& other):mRoot(nullptr){
    if (other.mRoot == nullptr) {
        return;
    }
    else if (other.mRoot->leftchild == nullptr && other.mRoot->rightchild == nullptr) {
        this->mRoot = new Node(other.mRoot->element);
    }
    else {
        Node * temp = other.mRoot;
        this->mRoot = Conhelper(temp);
    }
}


Set::Set(Set&& other){
    // if (other.mRoot == nullptr) {
    //     return;
    // }
    // else if (other.mRoot->leftchild == nullptr && other.mRoot->rightchild == nullptr) {
    //     this->mRoot = other.mRoot;
    // }
    // else {
    //     this->mRoot = moveh(other.mRoot);
    // }
    // other.mRoot = nullptr;
    std::cout << "using" << std::endl;
    this->mRoot = other.mRoot;
    other.mRoot = nullptr;
}

size_t Set::clear() {
    return clearh(mRoot,0);
}   

Set::~Set(){
    clear();
}