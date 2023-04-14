#include "FibVec.h"

// This provides exception types:
#include <stdexcept>
// using namespace std;

FibVec* create_fibvec() {
  // Used by the autograder to make a new FibVec.
  // You shouldn't need to change this.
  return new FibVec();
}


// FibVec Function Implementations

FibVec::FibVec() {
  size = f(2);
  Values = new int[size];
  indices = 2;
  counts = 0;
}

FibVec::~FibVec() {
  delete [] Values;
}

size_t FibVec::f(int n) {
  if (n==0) {
    return 0;
  }
  if (n==1) {
    return 1;
  }
  return (f(n-1) + f(n-2));
}

size_t FibVec::capacity() const{
  return size;
}

size_t FibVec::count() const{
  return counts;
}

void FibVec::insert(int value, size_t index) {
  if (index > counts) {
    throw std::out_of_range ("out of range!");
  }

  if (counts + 1 > size) {
    indices = indices + 1;
    size = f(indices);
  }
  int * array = new int[size];
  for (size_t i=0; i<counts; i++) {
    array[i] = Values[i];
  }
  

  array[index] = value;

  for (size_t i=index;i<counts+1;i++) {
    array[i+1] = Values[i];
  }
  delete [] Values;
  Values = array;
  counts = counts +1;
}

int FibVec::lookup(size_t index) const {
  if (index > counts-1) {
    throw std::out_of_range("out of range!");
  }
  return Values[index];
}

int FibVec::pop() {
  if (counts == 0) {
    throw std::underflow_error("underflow error!"); 
  }

  int result = Values[counts-1];
  counts = counts -1;
  
  //below is not tested
  if (counts < f(indices-2)){
    indices = indices-1;
    size = f(indices);
    int * arr = new int[size];
    for (size_t i=0; i<counts; i++) {
      arr[i] = Values[i];
    }
    delete[] Values;
    Values = arr;
  }

  return result;
}

void FibVec::push(int value){
  insert(value,counts);
}

int FibVec::remove(size_t index) {

  if (index > counts-1) {
    throw std::out_of_range ("out of range!");
  }

  int result = Values[index];
  if (counts-1 < f(indices-2)) {
    indices=indices-1;
    size = f(indices);
  }
  int * arr = new int[size];
  for (size_t i=0; i<counts; i++) {
    arr[i] = Values[i];
  }
  for (size_t i=index; i<counts-1; i++) {
    arr[i] = arr[i+1];
  }
  counts = counts -1;
  delete [] Values;
  Values = arr;
  return result;
}




