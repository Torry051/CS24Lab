#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <list>

#include <unordered_map>

#include "Report.h"
#include "Errors.h"

class Database
{
  // Member Variables
  std::unordered_map<unsigned int, const Report *> data;

  // Helper Functions

public:
  static Database *create();

public:
  Database();
  ~Database();

  void insert(const Report *report);
  std::vector<const Report *> search(float age, float height, float weight) const;
  void remove(unsigned int id);
};

#endif
