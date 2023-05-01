#include "Set.h"
#include <iostream>

// Use this file to test your Set class.
// This file won't be graded - do whatever you want.

int main() {
  Set set;

  // std::cout << "This program doesn't do anything interesting yet...\n";
  Set s;
  Node * n1 = new Node("10");
  Node * n2 = new Node("5");
  Node * n3 = new Node("15");
  Node * n4 = new Node("13");
  Node * n5 = new Node("1");
  Node * n6 = new Node("6");
  n2->leftchild = n5;
  n2->rightchild = n6;
  n3->leftchild = n4;
  n1->leftchild = n2;
  n1->rightchild = n3;
  s.mRoot = n1;
  std::cout << s.mRoot->leftchild->element << " " <<   s.mRoot->leftchild->leftchild->element   << " "<< s.mRoot->element << " " << s.mRoot->rightchild->element << " " << s.mRoot->rightchild->leftchild->element<<std::endl;
  Set s2(s);
  std::cout << s2.mRoot->leftchild->element << " " <<   s2.mRoot->leftchild->leftchild->element  << " "<< s2.mRoot->element << " " << s2.mRoot->rightchild->element << " " << s2.mRoot->rightchild->leftchild->element<< std::endl;
  size_t size;
  size = s.clear();

  std::cout << size << std::endl;


  return 0;
}
