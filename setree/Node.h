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
    // static Node * Conhelper(const Node *);
    // static size_t clearh(Node *, size_t);
    // static bool containh(Node *, const std::string &);
    // static size_t counth(Node *,size_t);
    // static size_t inserth(Node *, const std::string &);
    // static const std::string & lookh(Node *, size_t);
    // static const std::string printh(Node *);
    // static Node * removeh(Node *,const std::string &);
};

Node * Conhelper(const Node *);
size_t clearh(Node *, size_t);
bool containh(Node *, const std::string &);
size_t counth(Node *,size_t);
Node * inserth(Node *, const std::string &);
const std::string & lookh(Node *, size_t);
const std::string printh(Node *);
Node * removeh(Node *,const std::string &);
Node * insertNode(Node* n, Node * root);




#endif
