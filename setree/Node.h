#ifndef NODE_H
#define NODE_H

#include <string>

// Use this file to declare your Node type.
// Implement Node member functions and helper functions in Node.cpp.
class Node {
    public:
    std::string element;
    Node * leftchild;
    Node * rightchild;
    size_t count;

    Node();
    Node(const std::string &);
    Node(const std::string &, Node * leftchild, Node * rightchild);
};

Node * Conhelper(const Node * );
size_t clearh(const Node *, size_t size);


#endif
