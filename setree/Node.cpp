#include "Node.h"
#include <iostream>

Node::Node()  {
    element = "";
    leftchild = nullptr;
    rightchild = nullptr;
    count = 1;
}

Node::Node(const std::string &n) {
    element = n;
    leftchild = nullptr;
    rightchild = nullptr;
    count = 1;
}

Node * Conhelper( const Node * root) {
    Node * node = new Node(root->element);
    std::cout << "num: " << root->element << std::endl;
    if(root->leftchild == nullptr && root->rightchild == nullptr) {
        return node;
    }
    if(root->leftchild != nullptr) {
        node->leftchild = Conhelper(root->leftchild);
    }
    if(root->rightchild != nullptr) {
        node->rightchild =  Conhelper(root->rightchild);
    }
    return node;
}

Node::Node(const std::string &n, Node * left, Node * right) {
    element = n;
    leftchild = left;
    rightchild = right;
    count = 1;
}

size_t clearh(const Node *node, size_t size){
    if (node->leftchild == nullptr && node->rightchild ==nullptr) {
        delete node;
        size = 1;
    }
    if (node->leftchild != nullptr) {
        size = 1 + clearh(node->leftchild,0) + size;
        

    }
    if (node->rightchild != nullptr) {
        size = 1 + clearh(node->rightchild,0) + size;
    
    }

    delete node;
    return size;
}



