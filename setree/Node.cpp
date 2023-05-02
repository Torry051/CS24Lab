#include "Node.h"
#include <iostream>
#include <string>

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
    // std::cout << "running "<< std::endl;
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



size_t clearh(Node *n, size_t num){
    if (n==nullptr) {
        return 0;
    }

    if (n->leftchild == nullptr && n->rightchild == nullptr) {
        num = 1;
        // std::cout << "run3" << std::endl;
        delete n;
        n = nullptr;
        return num;
    }
    
    if (n->leftchild != nullptr) {
        num = 1 + clearh(n->leftchild,0);
        if (n->rightchild != nullptr) {
            num = num + clearh(n->rightchild,0);
        }
        // std::cout << "run2" << std::endl;
        delete n;
        n = nullptr;
        return num;
    }
    if (n->rightchild != nullptr){
        num = 1 + clearh(n->rightchild,0);
    
        //  std::cout << "run1" << std::endl;
        delete n;
        n = nullptr;
        return num;
    }
    return 0;
}

bool containh(Node * n, const std::string &value){
    if (n->element == value){
        return true;
    }
    if(n->leftchild == nullptr && n->rightchild == nullptr) {
        return false;
    }
    if (n->leftchild != nullptr){
        if (containh(n->leftchild,value)){
            return true;
        }
        else if (n->rightchild != nullptr){
            if (containh(n->rightchild,value)){
                return true;
            }
        }
        else {
            return false;
        }
    }
    if (n->rightchild != nullptr){
        return containh(n->rightchild,value);
    }
    return false;
}

size_t counth(Node *n, size_t num) {
    if(n==nullptr) {
        return 0;
    }

    if (n->leftchild == nullptr && n->rightchild == nullptr) {
        num = 1;
        // std::cout << "run3" << std::endl;
        return num;
    }
    
    if (n->leftchild != nullptr) {
        num = 1 + counth(n->leftchild,0);
        if (n->rightchild != nullptr) {
            num = num + counth(n->rightchild,0);
        }
        // std::cout << "run2" << std::endl;

        return num;
    }
    if (n->rightchild != nullptr){
        num = 1 + counth(n->rightchild,0);
    
        //  std::cout << "run1" << std::endl;

        return num;
    }
    return 0;
}

// size_t inserth(Node* n, const std::string & value){
//     if (n == nullptr){
//         return 1;
//         // std::cout << "run3" << std::endl;
//     }
//     if (n->element > value){
//         // std::cout << "run1" << std::endl;
//         if (inserth(n->leftchild, value) == 1){
//             Node * newnode = new Node(value);
//             n->leftchild = newnode;
//         }

//     }
//     else {
//         // std::cout << "run2" << std::endl;
//         if (inserth(n->rightchild,value) == 1){
//             Node * newnode = new Node(value);
//             n->rightchild = newnode;
//         }
//     }
//     return 1;
// }

Node * inserth(Node* n, const std::string & value){
    if (n == nullptr){
        Node * newnode = new Node(value);
        return newnode;
    }

    if (n->element > value){
        n->leftchild = inserth(n->leftchild,value);
    }
    else{
        n->rightchild = inserth(n->rightchild,value);
    }
    return n;
}

const std::string & lookh(Node *n, size_t num){
    if (num == 0){
        if(n->leftchild == nullptr){
            return n->element;
        }
        else {
            return lookh(n->leftchild,0);
        }
    }
    if (n->leftchild != nullptr) {
        if (counth(n->leftchild,0) > num){
            return lookh(n->leftchild,num);
        }
        else if (counth(n->leftchild,0) == num) {
            return n->element;
        }
        else{
            return lookh(n->rightchild,num-counth(n->leftchild,0)-1);
        }
    }
    else {
        return lookh(n->rightchild,num);
    }
}



const std::string printh(Node * n){
    if (n->leftchild == nullptr && n->rightchild == nullptr){
        if (n != nullptr){
            return n->element;
        }
    }
    if (n->leftchild != nullptr && n->rightchild != nullptr){
        return "(" + printh(n->leftchild) + " " + n->element + " " + printh(n->rightchild) + ")";
    }
    if (n->leftchild == nullptr && n->rightchild!= nullptr){
        return "(- " + n->element + " " + printh(n->rightchild)+ ")";
    }
    if (n->leftchild != nullptr && n->rightchild == nullptr){
        return "(" + printh(n->leftchild) + " " + n->element + " -)"; 
    }
    return "printh wrong";  
}


Node * removeh(Node * n, const std::string & value){
    
    if (n->element == value){
        if (n->leftchild !=nullptr && n->rightchild!= nullptr){
            Node * cpyr = n->rightchild;
            Node * cpyl = n->leftchild;

            delete n;
            n = cpyr;
            n->leftchild = cpyl;
            return n;
        }
        else if (n->leftchild == nullptr && n->rightchild == nullptr){
            delete n;
            return nullptr;
        }
        else if (n->leftchild != nullptr && n->rightchild == nullptr){
            Node * cpyl = n->leftchild;
            delete n;
            n = cpyl;
            return n;
        }
        else{
            Node * cpyr = n->rightchild;
            delete n;
            n = cpyr;
            return n;
        }
    }
    
    
    
    if (n->element > value){
        if (n->leftchild!=nullptr) {
            n->leftchild = removeh(n->leftchild, value);
            return n;
        }
        else{
            std::cout << "remove wrong1" << std::endl;
            return n;
        }
    }

    if (n->element < value){
        if (n->rightchild != nullptr){
             n->rightchild = removeh(n->rightchild,value);
            return n;
        }
    }

    std::cout << "remove wrong2" << std::endl;
    return n;
}