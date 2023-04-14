#ifndef FIBVEC_H
#define FIBVEC_H

// This provides the size_t type:
#include <cstddef>

// using namespace std;

class FibVec {
  // Member Variables
public:
  int * Values;
  size_t size;
  size_t indices;
  size_t counts;
  // Helper Functions
  size_t f(int n);
public:
  // Constructor and Destructor
  FibVec();
  ~FibVec();
  // Member Functions
  size_t capacity();
  size_t count();
  void insert(int , size_t);
  int lookup(size_t index) const;
  int pop();
  void push(int value);
  int remove(size_t index);
};

// Used by the autograder:
FibVec* create_fibvec();

#endif
