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

            Word * w = new Word(word);
            allwords.push_back(w);
            new_graph[word] = w;
            for (size_t i = 0; i < word.size(); i++)
            {
                std::string template_word = word;
                template_word[i] = '_'; // generate all template words
                this->graph[template_word].push_back(w);
                for (size_t j = 0; j<this->graph[template_word].size()-1; j++){
                        this->graph[template_word].at(j)->neighbours.push_back(w);
                        w->neighbours.push_back(this->graph[template_word].at(j));
                }
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

std::map<std::string, Word*> Dictionary::link(const std::string &from, const std::string &to)
{
    std::map<std::string, Word*> visited; // a map with key of the word and a word of how we got there
    std::queue<std::string> queue;              // a queue(deque) to keep track of the bfs process

    std::string currword = from; // we need to start with "from"
    // std::string trace = " ";
    queue.push(currword); // push the first word into queue

    // size_t i = 0;

    while (queue.size())
    {
        currword = queue.front(); // update the next word for our search
        // std::cout << currword << std::endl;
        if (currword == to){
            return visited;
        }
        // std::cout << currword << std::endl;

        for(size_t i=0; i< new_graph[currword]->neighbours.size();i++){
        
            std::string neighbour = new_graph[currword]->neighbours.at(i)->str;
            
            if(visited.count(neighbour)==0){
                visited[neighbour]= new_graph[currword];
                queue.push(neighbour);
            }

        }
        queue.pop();

        // i++;

        // if(i>25){
        //     break;
        // }

    }
    return visited;

}

std::vector<std::string> Dictionary::hop(const std::string &from, const std::string &to)
{
    if (from.size() != to.size())
    {
        throw NoChain();
    }

    if(this->new_graph.count(from)==0 || this->new_graph.count(to)==0){
         throw InvalidWord("from or to word does not exist");
    }
    // if from or to is not in graph at the very beginning, we do not need link
    std::vector<std::string> result;
    if (from == to)
    {
        result.push_back(from);
        return result;
    }

    std::vector<std::string> chain;
    std::map<std::string, Word *> Map;
    Map = link(from, to);
    std::string curr = to;
    // /*for (auto i = Map.begin(); i != Map.end(); i++)
    // {
    //     std::cout << "after change:" << i->first << " before change:" << i->second;
    //     std::cout << "\n";
    // }*/
    
  
    if(Map.count(to)==0){
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
//-------------------------------------------------------------------------------------------------
/*void Dictionary::print() const
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
}*/

Dictionary::~Dictionary(){
    for(auto itr = new_graph.begin(); itr!=new_graph.end(); itr++){
        delete itr->second;
    }
}