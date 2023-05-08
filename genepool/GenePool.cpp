#include "GenePool.h"
#include <sstream>
#include <iostream>
#include <vector>

// GenePool Member Functions
GenePool::GenePool(std::istream& stream){
    // std::cout << "running" <<std::endl;
    std::string Sinfo;
    std::string name;
    std::string gender;
    std::string motherName;
    std::string fatherName;
    std::vector<Person*> All;
    std::vector<std::string> Allname;  
    
    while(std::getline(stream,Sinfo)){
        if (Sinfo.size()==0){
            continue;
        }
        std::istringstream info(Sinfo);
        if (Sinfo[0] != '#'){
            std::getline(info,name,'\t');
            // std::cout << name << std::endl;
            std::getline(info,gender,'\t');
            std::getline(info,motherName,'\t');
            std::getline(info,fatherName,'\t');
            Person * p = new Person(name,gender,motherName, fatherName); 
            All.push_back(p);
            Allname.push_back(name);
            mymap[name] = p;
            // std::cout << mymap.size()<< std::endl;
        }
    }

    for (unsigned i = 0; i< All.size();i++){
        motherName = All.at(i)->motherN();
        fatherName = All.at(i)->fatherN();
        // std::cout << Allname.at(i) << std::endl;
        if (motherName == "???" && fatherName == "???"){
            All.at(i)->m(nullptr);
            All.at(i)->f(nullptr);
            continue;
        }
        if (motherName == "???" ){
            All.at(i)->m(nullptr);
        }
        if (fatherName == "???") {
            All.at(i)->f(nullptr);
        }
        // std::cout << "running2"<< std::endl;
        if(motherName == "???" && fatherName == "???"){
            continue;
        }

        for(unsigned j = 0; j<Allname.size();j++){
            if(Allname.at(j)==motherName){
                All.at(i)->m(All.at(j));
            }
            if(Allname.at(j)==fatherName){
                All.at(i)->f(All.at(j));
            }
        } 
    }
      
    for(auto & person: mymap){
        std::set<Person*> result1;
        name = person.first;
        // std::cout <<"name:" << name << '\t';
        if (mymap[name]->gender()==Gender::MALE){
            for(auto & child: mymap){
                if (name == child.second->fatherN()){
                    result1.insert(child.second);
                }
            }   
        }
        else if (mymap[name]->gender()==Gender::FEMALE){
            for (auto & child: mymap){
                if (name == child.second->motherN()){
                    result1.insert(child.second);
                }
            }
        }
        else{
            std::cout << "Wrong" <<std::endl;
        }
        
        
        // std::cout << "running1" <<std::endl;
        person.second->Children = result1;
    }
    
    
}

GenePool::~GenePool(){
    // std::cout << "Destructure running" << std::endl;
    for(auto & person: mymap){
        delete person.second;
        person.second = nullptr; 
    }
}

std::set<Person*> GenePool::everyone() const{
    std::set<Person *> result;
    for(auto & person: mymap){
        result.insert(person.second);
    }
    return result;
}

Person* GenePool::find(const std::string& name) const{
    for(auto & person: mymap){
        if (person.first == name){
            return person.second;
        }
    }
    return nullptr;
}