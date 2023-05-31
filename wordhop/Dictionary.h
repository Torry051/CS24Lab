#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <cstddef>
#include <cctype>
#include "Errors.h"
#include <list>
#include <time.h>

struct Word
{
	std::string str;
	std::vector<Word *> neighbours;

	Word(std::string s)
	{
		str = s;
	};
};
class Dictionary
{
	// Member Variables
public:
	std::unordered_map<std::string, std::vector<Word *>> graph; // a graph with template strings as keys, and pointers in a vector to Words. which is it's neightbour
	std::unordered_map<std::string, Word *> new_graph;		  // a graph with string itself as keys and only to it's cloest neighbours

public:
	// default constructor
	Dictionary(std::istream &);
	~Dictionary();

	// The create function used by the autograder:
	static Dictionary *create(std::istream &stream);

	// test print, only to see how it works
	/*void print_graph() const;
	void print_allwords() const;
	void print_newgraph() const;*/

public:
	// The function that does all the work:
	std::vector<std::string> hop(const std::string &from, const std::string &to);

	// a helper that generates a map with all changes, traced therefore can find the chain (this is what professor Burk said)
	std::unordered_map<std::string, Word *> link(const std::string &from, const std::string &to);
};

#endif
// dhwuid