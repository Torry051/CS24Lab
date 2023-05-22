#include "WordList.h"

WordList::WordList(std::istream& stream){
    std::string line;
    while(std::getline(stream,line)){
        bool lower = true;
        if (line[0]=='#'){
            continue;
        }
        for(size_t i = 0; i<line.length();i++){
            if (!(islower(line[i]))){
                lower = false;
                break;
            }
        }
        if(lower){
            mWords.push_back(line);
        }
    }
}

Heap WordList::correct(const std::vector<Point>& points, size_t maxcount, float cutoff) const{
    Heap heap(mWords.size());
    std::string str;
    size_t index = 0;

    for (size_t i = 0; i < mWords.size(); i++){
        str = mWords.at(i);
        float scores = 0;
        for (size_t j = 0; j < str.length(); j++){
            float d = 0;
            d = (points.at(index).x - QWERTY[str[j]-'a'].x) * (points.at(index).x - QWERTY[str[j]-'a'].x) + (points.at(index).y - QWERTY[str[j]-'a'].y) * (points.at(index).y - QWERTY[str[j]-'a'].y);
            scores += 1/(10*d*d+1);
            index = index + 1;
        }
        scores = scores/(str.length());
        heap.push(str,scores);
    }

    while(heap.count()>maxcount){
        heap.pop(); 
    }
    Heap result(maxcount);
    for(size_t z = 0; z < maxcount; z++){
        Heap::Entry E = heap.pop();
        result.push(E.value,E.score);
    }
    for (size_t i =0; i< cutoff; i++){
        Heap::Entry E = result.pop();
    }
    return result;
}