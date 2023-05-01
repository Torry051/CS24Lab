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
};

Node * Conhelper(const Node *);
size_t clearh(Node *, size_t);
bool containh(Node *, const std::string &);
size_t counth(Node *,size_t);
size_t inserth(Node *, const std::string &);
const std::string & lookh(Node *, size_t);
const std::string printh(Node *, std::string);
Node * removeh(Node *, const std::string &);


#endif
