#include "FibVec.h"
#include <iostream>

// Use this file to test your FibVec class!
// This file won't be graded - do whatever you want.

int main() {
  FibVec fibvec;
  // std::cout << fibvec.capacity() << " " << fibvec.size << std::endl;
  // fibvec.insert(3,3);
  // std::cout << "This program doesn't do anything interesting yet...\n";
  // std::cout << fibvec.f(6) << std::endl;
  fibvec.insert(5,0);
  fibvec.insert(10,0);
  fibvec.insert(15,1);
  fibvec.insert(20,3);
  fibvec.insert(100,2);
  fibvec.insert(520,1);

  // for (size_t i=0; i<fibvec.counts;i++) {
  //   std::cout << fibvec.Values[i] << " ";
  // }
  // std::cout << std::endl;

  // std::cout <<"size: " << fibvec.size << " indices: " << fibvec.indices << std::endl;
  // int index;
  // std::cout << "input the index:" << std::endl;
  // std:: cin >> index;
  // std::cout << "the index: " << index << " the number: " << fibvec.lookup(index) << std::endl;

  // std::cout << "pop number: " << fibvec.pop() << std::endl;
  // std::cout << "pop number: " << fibvec.pop() << std::endl;
  // std::cout << "pop number: " << fibvec.pop() << std::endl;
  // std::cout << "pop number: " << fibvec.pop() << std::endl;
  // fibvec.remove(0);
  // std::cout << "The vector: ";
  // for (size_t i=0; i<fibvec.counts;i++) {
  //   std::cout << fibvec.Values[i] << " ";
  // }
  // std::cout << std::endl;

  // std::cout <<"size: " << fibvec.size << " indices: " << fibvec.indices << " counts:" << fibvec.counts << std::endl;
  // fibvec.push(111);
  // fibvec.push(112);
  // fibvec.push(113);
  // fibvec.push(114);
  // std::cout << "The vector: ";
  // for (size_t i=0; i<fibvec.counts;i++) {
  //   std::cout << fibvec.Values[i] << " ";
  // }
  // std::cout << std::endl;
  // std::cout <<"size: " << fibvec.size << " indices: " << fibvec.indices << " counts:" << fibvec.counts << std::endl;
  
  // std::cout << "index 2: " << fibvec.lookup(2) << std::endl;
  // fibvec.remove(2);
  // std::cout << "index 2: " << fibvec.lookup(2) << std::endl;

  return 0;
}
