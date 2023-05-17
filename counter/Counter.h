#ifndef COUNTER_H
#define COUNTER_H

#include <cstddef>
#include <string>
#include "Index.h"

// This is the Counter class you need to implement.
// It includes the Counter::Iterator as a nested class.
// If you want more space to implement helper classes,
// you can use the DataStore.* and Index.* files.

class Counter {
public:
  class Iterator {
    // Member Variables
    public:
    Node * nod;

    // DataStore _Data;

  public:
    Iterator():nod(nullptr){};
    Iterator(Node *n):nod(n){
      // std::cout << "running: " << nod->str <<std::endl;
    };
    ~Iterator();
    const std::string& key() const;
    int value() const;

    Iterator& operator ++ ();
    bool      operator == (const Iterator& other) const;
    bool      operator != (const Iterator& other) const;
  };

private:
  // Member Variables
  Index table;
  size_t size;
  Node * e;
 


private:
  // Helper Functions

public:
  Counter():table(Index()), size(0),e(nullptr){};
  ~Counter();

  size_t count() const;
  int    total() const;

  void inc(const std::string& key, int by = 1);
  void dec(const std::string& key, int by = 1);
  void del(const std::string& key);
  int  get(const std::string& key) const;
  void set(const std::string& key, int count);

  Iterator begin() const;
  Iterator end();
};

#endif
