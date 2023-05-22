#include "WordList.h"
#include <iostream>
#include <cmath>

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
    // for (size_t i = 0; i<mWords.size(); i++){
    //     std::cout << mWords.at(i) <<std::endl;
    // }
    // std::cout << "ending: "<< mWords.size() <<std::endl;
}

Heap WordList::correct(const std::vector<Point>& points, size_t maxcount, float cutoff) const{
    Heap result(maxcount);
    std::string str;

    for (size_t i = 0; i < mWords.size(); i++){
        str = mWords.at(i);
        float scores = 0;
        if (str.length()!=points.size()){
            continue;
        }
        for (size_t j = 0; j < points.size(); j++){
            float d = 0;
            d = sqrt((points.at(j).x - QWERTY[str[j]-'a'].x) * (points.at(j).x - QWERTY[str[j]-'a'].x) + (points.at(j).y - QWERTY[str[j]-'a'].y) * (points.at(j).y - QWERTY[str[j]-'a'].y));
            scores += 1/(10*d*d+1);
        }
        scores = scores/(str.length());
        
        if (result.count() < maxcount){
            result.push(str,scores);
        }
        else {
            if(result.top().score < scores){
                result.pushpop(str,scores);
            }
        }
    }

    while(result.top().score < cutoff){
        Heap::Entry E = result.pop();
        if (result.count()==0){
            break;
        }
    }
    // std::cout << "check: "<<result.count() <<std::endl;
    return result;
}