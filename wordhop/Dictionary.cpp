#include "Dictionary.h"

// the constructor should be done
Dictionary::Dictionary(std::istream &stream)
{
    std::string word;
    bool is_valid = 1; // record if the word is a valid word
    while (getline(stream, word))
    {
        if (word[0] == '#') // if the line starts with #, omit the line
        {
            continue;
        }
        for (size_t i = 0; i < word.size(); i++) // loop through all letters in a word
        {
            if (islower(word[i]) == 0) // if a letter is not in lower case, then it's invalid
            {
                is_valid = 0;
            }
        }
        if (is_valid == 1) // if the word is valid
        {
            for (size_t i = 0; i < word.size(); i++)
            {
                std::string template_word = word;
                template_word[i] = '_'; // generate all template words
                this->graph[template_word].push_back(word);
            }
        }
        is_valid = 1; // reset to valid for next loop
    }
}

Dictionary *Dictionary::create(std::istream &stream)
{
    Dictionary *dictionary = new Dictionary(stream);
    return dictionary;
}

std::map<std::string, std::string> Dictionary::link(const std::string &from, const std::string &to)
{
    std::map<std::string, std::string> visited; // a map with key of the word and a word of how we got there
    std::deque<std::string> queue;              // a queue(deque) to keep track of the bfs process

    std::string currword = from; // we need to start with "from"
    std::string trace = " ";
    queue.push_back(currword); // push the first word into queue

    while (queue.size())
    {
        currword = queue.front(); // update the next word for our search
        // std::cout << currword << std::endl;

        // if (visited.count(currword) > 0)
        // {
        //     queue.pop_front();
        //     continue;
        // }

        for (size_t i = 0; i < currword.size(); i++)
        {
            std::string template_word = currword;
            template_word[i] = '_';                                        // loop through each template word
            for (size_t j = 0; j < this->graph[template_word].size(); j++) // loop through all neighbours (1st level)
            {
                std::string neighbour = this->graph[template_word].at(j);

                // make sure we are not inserting the same element into the queue as well
                // bool in_queue = 0;
                // for (size_t k = 0; k < queue.size(); k++)
                // {
                //     if (queue.at(k) == neighbour)
                //         in_queue = 1;
                // }
                // if (in_queue == 0 && visited.count(neighbour) == 0)
                if (visited.count(neighbour) == 0)
                {
                    // std::cout << neighbour << " : ";
                    queue.push_back(neighbour);
                    visited[neighbour] = currword;   
                }
                // in_queue = 0;
            }
        }
        // std::cout << "next: " <<std::endl;

        // update the dictionary fo tracing
        // visited[currword] = trace;
        // trace = currword; 

        

        // move forward in the queue
        queue.pop_front();
    }
    for (auto i = visited.begin(); i != visited.end(); i++)
    {
        std::cout << "after change:" << i->first << " before change:" << i->second;
        std::cout << "\n";
    }
    return visited;
}

std::vector<std::string> Dictionary::hop(const std::string &from, const std::string &to)
{
    std::vector<std::string> chain;
    std::vector<std::string> result;
    std::map<std::string, std::string> Map;
    Map = link(from, to);
    std::string curr = to;

    bool exist = false;

    for(auto itr = Map.begin(); itr != Map.end(); itr++){
        if (itr->first == to){
            exist = true;
        }
    }

    if (exist == false){
        throw NoChain();
    }

    if(from.size() != to.size()){
        throw InvalidWord("invalid word");
    }

    if(from == to){
        throw NoChain();
    }
  
    while(Map[curr]!=from){
        chain.push_back(Map[curr]);
        curr = Map[curr];
    }

    result.push_back(from);

    for (size_t i = 0; i < chain.size(); i++){
        size_t j = chain.size() - 1-i;
        result.push_back(chain.at(j));
    }
    result.push_back(to);


    return result;
    // I believe what should be done here is simply trace back: use the "to" to find the track of changes (shouldn't be hard)
}
//-------------------------------------------------------------------------------------------------
void Dictionary::print() const
{
    for (auto i = this->graph.begin(); i != this->graph.end(); i++)
    {
        std::cout << i->first << "    ";
        for (auto j = 0; j < i->second.size(); j++)
        {
            std::cout << i->second[j] << " ";
        }
        std::cout << "\n";
    }
}