#include "Dictionary.h"

// the constructor should be done
Dictionary::Dictionary(std::istream &stream)
{
    // float start = clock();

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

            Word *w = new Word(word);
            new_graph[word] = w;
            for (size_t i = 0; i < word.size(); i++)
            {
                std::string template_word = word;
                template_word[i] = '_'; // generate all template words
                this->graph[template_word].push_back(w);
                for (size_t j = 0; j < this->graph[template_word].size() - 1; j++)
                {
                    this->graph[template_word].at(j)->neighbours.push_back(w);
                    w->neighbours.push_back(this->graph[template_word].at(j));
                }
            }
        }
        is_valid = 1; // reset to valid for next loop
    }
    // float end = clock();
    // std::cout << "time used by constructor" << (end - start) / CLOCKS_PER_SEC << "\n";
}

Dictionary *Dictionary::create(std::istream &stream)
{
    Dictionary *dictionary = new Dictionary(stream);
    return dictionary;
}

std::unordered_map<std::string, Word *> Dictionary::link(const std::string &from, const std::string &to)
{
    std::unordered_map<std::string, Word *> visited; // a map with key of the word and a word of how we got there
    std::queue<Word *> queue;                        // a queue to keep track of the bfs process

    Word *temp_word = this->new_graph[from];
    queue.push(temp_word); // push the first word into queue

    visited.reserve(1000);
    while (queue.size())
    {
        Word *currWord = queue.front(); // update the next word for our search
        std::string currstr = currWord->str;
        if (currstr == to)
        {
            return visited;
        }
        temp_word = this->new_graph[currstr];
        for (Word *neighbour : temp_word->neighbours)
        {
            std::string neighbour_str = neighbour->str;
            if (visited.count(neighbour_str) == 0)
            {
                visited[neighbour_str] = temp_word;
                queue.push(neighbour);
            }
        }
        /*for (size_t i = 0; i < new_graph[currword]->neighbours.size(); i++)
        {

            std::string neighbour = new_graph[currword]->neighbours.at(i)->str;

            if (visited.count(neighbour) == 0)
            {
                visited[neighbour] = new_graph[currword];
                queue.push(neighbour);
            }
        }*/
        queue.pop();
    }
    return visited;
}

std::vector<std::string> Dictionary::hop(const std::string &from, const std::string &to)
{
    if (from.size() != to.size())
    {
        throw NoChain();
    }

    // if from or to is not in graph at the very beginning, we do not need link
    if (this->new_graph.count(from) == 0 || this->new_graph.count(to) == 0)
    {
        throw InvalidWord("from or to word does not exist");
    }

    // if from is to at the beginning, we simply output from
    std::vector<std::string> result;
    if (from == to)
    {
        result.push_back(from);
        return result;
    }

    std::vector<std::string> chain;
    std::unordered_map<std::string, Word *> Map;

    // float start = clock();
    Map = link(from, to);
    // float end = clock();
    // std::cout << "time used in link function: " << (end - start) / CLOCKS_PER_SEC << "\n";

    std::string curr = to;

    if (Map.count(to) == 0)
    {
        throw NoChain();
    }

    while (Map[curr]->str != from)
    {
        chain.push_back(Map[curr]->str);
        curr = Map[curr]->str;
    }

    result.push_back(from);

    for (size_t i = 0; i < chain.size(); i++)
    {
        size_t j = chain.size() - 1 - i;
        result.push_back(chain.at(j)); // list may be better
    }
    result.push_back(to);

    return result;
}

Dictionary::~Dictionary()
{
    for (auto itr = new_graph.begin(); itr != new_graph.end(); itr++)
    {
        delete itr->second;
    }
}
//-------------------------------------------------------------------------------------------------
/*void Dictionary::print_graph() const
{
    for (auto i = this->graph.begin(); i != this->graph.end(); i++)
    {
        std::cout << i->first << "    ";
        for (auto j = 0; j < i->second.size(); j++)
        {
            std::cout << i->second[j]->str << " ";
        }
        std::cout << "\n";
    }
}
void Dictionary::print_allwords() const
{
    for (size_t i = 0; i < this->allwords.size(); i++)
    {
        std::cout << this->allwords.at(i) << " ";
    }
    std::cout << "\n";
}
void Dictionary::print_newgraph() const
{
    for (auto i = this->new_graph.begin(); i != this->new_graph.end(); i++)
    {
        std::cout << i->first << " " << i->second->str << "\n";
    }
}*/