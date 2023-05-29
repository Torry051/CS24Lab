#include "Dictionary.h"
#include "Errors.h"

#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "USAGE: " << argv[0] << " [words-file]\n";
		return 1;
	}

	Dictionary *dictionary = nullptr;

	try
	{
		std::ifstream file(argv[1]);
		if (file.fail())
		{
			std::cerr << "Could not open file: " << argv[1] << '\n';
			return 1;
		}

		dictionary = Dictionary::create(file);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error reading words file: " << e.what() << '\n';
		return 1;
	}

	// std::cout << "Graph: " << std::endl;

	// for (auto itr = dictionary->graph.begin(); itr != dictionary->graph.end(); itr++){
	// 	std::cout << itr->first << ": ";
	// 	for (size_t i = 0; i < itr->second.size(); i++){
	// 		std::cout<<itr->second.at(i)->str << " " <<std::endl;
	// 		std::cout << "neighbours: ";
	// 		for (size_t j = 0; j<itr->second.at(i)->neighbours.size();j++){
	// 			std::cout<<itr->second.at(i)->neighbours.at(j)->str << " ";
	// 		}
	// 		std::cout << "\n";
	// 	}
	// 	std::cout << "\n"; 	
	// }
	

	// for (auto itr = dictionary->new_graph.begin(); itr!= dictionary->new_graph.end(); itr++){
	// 	std::cout << itr->first <<": ";
	// 	std::cout << "neighbours: ";
	// 	for (size_t z =0; z < itr->second->neighbours.size();z++){
	// 		std::cout << itr->second->neighbours.at(z)->str << " ";
	// 	}
	// 	std::cout << "\n";
	// }
	// std::cout << dictionary->allwords.size() <<std::endl;

	// for (size_t j = 0; j < dictionary->allwords.size(); j++){
	// 	std::cout << dictionary->allwords.at(j)->str << std::endl;
	// 	std::cout << "neighbours: ";
	// 	for (size_t i = 0; i< dictionary->allwords.at(j)->neighbours.size();i++){
	// 		std::cout << dictionary->allwords.at(j)->neighbours.at(i)->str << " ";
	// 	}
	// 	std::cout << "\n";
	// }


	// can be deleted, this is only printing out the dictionary after the constructor to show how it works
	// dictionary->print();

	while (true)
	{
		std::string from;
		std::string to;

		std::cout << "From: ";
		if (!std::getline(std::cin, from))
		{
			break;
		}

		std::cout << "To:   ";
		if (!std::getline(std::cin, to))
		{
			break;
		}

		// std::map<std::string, std::string> chain = dictionary->link(from, to);
		// std::vector<std::string> result = dictionary->hop(from,to);
		// std::cout << "result" <<std::endl;
		// for(size_t i = 0; i < result.size();i++){
		// 	std::cout << result.at(i) <<std::endl;
		// }
		try
		{

			std::vector<std::string> chain = dictionary->hop(from, to);
			for (const std::string &word : chain)
			{
				std::cout << " - " << word << '\n';
			}
		}
		catch (const NoChain &e)
		{
			std::cout << "No chain.\n";
		}
		catch (const InvalidWord &e)
		{
			std::cout << "Invalid word: " << e.what() << '\n';
		}
		catch (const std::exception &e)
		{
			std::cerr << "ERROR: " << e.what() << '\n';
		}
	}

	delete dictionary;
	return 0;
}
