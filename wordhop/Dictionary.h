#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstddef>
#include <cctype>
#include "Errors.h"
#include <list>

class Dictionary
{
	// Member Variables
	std::map<std::string, std::vector<std::string>> graph;
	// this is a map (as what professor burk mentioned this morning: a template string pointing to all it's neighbours)

public:
	// default constructor
	Dictionary(std::istream &);

	// The create function used by the autograder:
	static Dictionary *create(std::istream &stream);

	// testing print function, you should be able to see how the constructor works
	// void print() const;

public:
	// The function that does all the work:
	std::vector<std::string> hop(const std::string &from, const std::string &to);

	// a helper that generates a map with all changes, traced therefore can find the chain (this is what professor Burk said)
	std::map<std::string, std::string> link(const std::string &from, const std::string &to);
};

#endif
