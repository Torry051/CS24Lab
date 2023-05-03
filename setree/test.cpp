#include "Set.h"
#include <iostream>
#include <string>

// Use this file to test your Set class.
// This file won't be graded - do whatever you want.
int main() {
  // Set set;

  // std::cout << "This program doesn't do anything interesting yet...\n";
  // Set s;
  // Node * n1 = new Node("10");
  // Node * n2 = new Node("5");
  // Node * n3 = new Node("15");
  // Node * n4 = new Node("13");
  // Node * n5 = new Node("1");
  // Node * n6 = new Node("6");
  // Node * n1 = new Node("Fides");
  // Node * n2 = new Node("Operatio");
  // Node * n3 = new Node("Pudicitia");
  // n2->leftchild =n1;
  // n2->rightchild=n3;
  // s.mRoot = n2;
  // Set s1(s);
  // Std::cout << s.mRoot->element;
  // s1.print();
  // std::cout << std::endl;
  // Node * n4 = new Node("d");
  // Node * n5 = new Node("e");
  // Node * n6 = new Node("f");
  // n2->leftchild = n1;
  // n2->rightchild = n3;
  // n5->rightchild = n6;
  // n4->leftchild = n2;
  // n4->rightchild = n5;
  // s.mRoot = n4;
  // n2->leftchild = n5;
  // n2->rightchild = n6;
  // n3->leftchild = n4;
  // n1->leftchild = n2;
  // n1->rightchild = n3;
  // s.mRoot = n1;
  // std::cout << s.mRoot->leftchild->element << " " <<   s.mRoot->leftchild->leftchild->element   << " "<< s.mRoot->element << " " << s.mRoot->rightchild->element << " " << s.mRoot->rightchild->leftchild->element<<std::endl;
  // Set s2(s);
  // std::cout << s2.mRoot->leftchild->element << " " <<   s2.mRoot->leftchild->leftchild->element  << " "<< s2.mRoot->element << " " << s2.mRoot->rightchild->element << " " << s2.mRoot->rightchild->leftchild->element<< std::endl;
  // std::cout << s.mRoot->leftchild->element << " " << s.mRoot->element << " "<< s.mRoot->rightchild->element << std::endl;
  // size_t size;
  // size = s.clear();

  // std::cout << size << std::endl;
  // if (s.contains("5")){
  //   std::cout << "yes " << std::endl;
  // }
  
  
  // std::cout << s.count() << std::endl;
  // std::cout << s.insert("11") << std::endl;
  // std::cout << s.count() << std::endl;
  //   if (s.contains("11")){
  //   std::cout << "yes " << std::endl;
  // }

  // std::cout << s.mRoot->rightchild->leftchild->leftchild->element << std::endl;
  // std::cout << s.lookup(2) << std::endl;
  // s.print();
  // std::cout << std::endl;

  // s.remove("b");
  // s.print();
  // std::cout << std::endl;

  Set s;

  s.insert("50");
  s.insert("20");
  s.insert("60");
  s.insert("10");
  s.insert("30");
  s.insert("35");
  s.insert("25");
  s.insert("55");
  s.insert("70");
  s.insert("80");
  s.insert("65");
  // s.insert("20");
  // s.insert("19");
  s.print();
  s.remove("20");
  // s.remove("80");
  s.print();
  // std::cout << s.mRoot->rightchild->element <<std::endl;
  
  // std::string s1 = "15";
  // std::string s2 = "5";
  
  // if(s2>s1){
  //   std::cout << "yes" <<std::endl;
  // }



  return 0;
}
