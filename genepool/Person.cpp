#include "Person.h"

#include <iostream>
// Person Member Functions
const std::string& Person::name()   const{
    return Name;
}

Gender Person::gender() const {
    return Gen;
}

Person* Person::mother() {
    return Mother;
}

Person * Person::father() {
    return Father;
}

Person::Person(){
    Name = "";
    Gen = Gender::ANY; 
    Mother = nullptr;
    Father = nullptr;
    // Siblings = nullptr;
    std::set<Person*> result;
    Children = result;
}

std::string Person::motherN(){
    return MotherName;
}

std::string Person::fatherN(){
    return FatherName;
}

Person::Person(std::string name, std::string gen, std::string mother,std::string father){
    this->Name = name;
    if (gen == "male"){
        this->Gen = Gender::MALE; 
    }
    else if (gen == "female"){
        this->Gen = Gender::FEMALE;
    }
    else{
        this->Gen = Gender::ANY;
    }
    this->Mother = nullptr;
    this->Father = nullptr;
    this->MotherName = mother;
    this->FatherName = father;
    // Siblings = nullptr;
    std::set<Person*> result;
    Children = result;
}

void Person::m(Person *mother){
    this->Mother = mother;
}
void Person::f(Person *father){
    this->Father = father;
}

std::set<Person *> Person::add(Person * root,std::set<Person*> Set){
    if (root->Mother == nullptr && root->Father == nullptr){
        Set.insert(root);
        return Set;
    }
    if (root->Mother != nullptr && root->Father != nullptr){
        Set.insert(root);
        Set = add(root->Mother,Set);
        Set = add(root->Father,Set);
        return Set;
    }
    if (root->Mother != nullptr && root->Father == nullptr){
        Set.insert(root);
        Set = add(root->Mother,Set);
        return Set;
    }

    if (root->Mother == nullptr && root->Father != nullptr){
        Set.insert(root);
        Set = add(root->Father,Set);
        return Set;
    }
    std::cout << "adding wrong" <<std::endl;
    return Set;
}

std::set<Person*> Person::ancestors(PMod pmod){
    std::set<Person*> result;
    if (pmod == PMod::ANY){
        if(Mother==nullptr && Father == nullptr){
           return result; 
        }
        else if(Mother != nullptr && Father != nullptr){
            result = add(this->Mother,result);
            result = add(this->Father,result);
        }
        else if(Mother!=nullptr && Father == nullptr){
            result = add(this->Mother,result);
        }
        else if(Father!=nullptr && Mother == nullptr){
            result = add(this->Father,result);
        }
        return result;
    }
    else if(pmod == PMod::PATERNAL){
        if(Father != nullptr){
            result = add(this->Father,result);
        }
        else{
            return result;
        }
        return result;   
    }
    else{
        if(Mother != nullptr){
            result = add(this->Mother,result);
        }
        else{
            return result;
        }
        return result;
    }
}



std::set<Person*> Person::brothers(PMod pmod, SMod smod){
    std::set<Person*> result;
    std::set<Person*> all;
    
    if (fatherN()!="???" &&Father->children().size()!=0){
        // std::cout << "running" <<std::endl;
        for (auto & child: Father->children()){

            if (child->gender() == Gender::MALE&&child->name ()!= Name){

                all.insert(child);
            }
        }
    }
    // std::cout << "running1" <<std::endl;
    if (motherN() !="???"   &&Mother->children().size()!=0){
        for (auto & childr: Mother->children()){
            if (childr->gender() == Gender::MALE && childr->name() != Name){
                all.insert(childr);
            }   
        }
    }
    if (pmod == PMod::ANY && smod == SMod::ANY){
        return all;
    }
    if (pmod == PMod::PATERNAL && smod == SMod::HALF){
        for(auto & child : all){
            if (child->FatherName == this->FatherName && child->MotherName != this -> MotherName){
                result.insert(child);
            }
        }
        return result;
    }
    if(pmod == PMod::PATERNAL && smod == SMod::ANY){
        if (father()==nullptr){
            // std::cout << "runnign"<<std::endl;
            return result;
        }
        for(auto & child : all){
            if (child->FatherName == this->FatherName){
                result.insert(child);
            }
        }
        return result;
    }
    
    if (pmod == PMod::MATERNAL && smod == SMod::HALF){
        for(auto & child : all){
            if (child->FatherName != this->FatherName && child->MotherName == this -> MotherName){
                result.insert(child);
            }
        }
        return result;
    }

    if(pmod == PMod::MATERNAL && smod == SMod::ANY){
        if (mother() == nullptr){
            // std::cout << "r" <<std::endl;
            return result;
        }
        // std::cout << "ru" <<std::endl;
        for(auto & child : all){
            if (child->MotherName == this->MotherName){
                result.insert(child);
            }
        }
        return result;
    }

    if (pmod == PMod::ANY && smod == SMod::FULL){
        if (mother()==nullptr || father() == nullptr){
            return result;
        }
        for(auto & child : all){
            if (child->FatherName == this->FatherName && child->MotherName == this -> MotherName){
                result.insert(child);
            }
        }
        return result;
    }
    if (pmod == PMod::PATERNAL && smod == SMod::FULL){
        for(auto & child : all){
            if (child->FatherName == this->FatherName && child->MotherName == this -> MotherName){
                result.insert(child);
            }
        }
        return result;
    }
    if (pmod == PMod::MATERNAL && smod == SMod::FULL){
        for(auto & child : all){
            if (child->FatherName == this->FatherName && child->MotherName == this -> MotherName){
                result.insert(child);
            }
        }
        return result;
    }
    if (pmod == PMod::ANY && smod == SMod::HALF){
        for(auto & child : all){
            if (child->FatherName != this->FatherName && child->MotherName == this -> MotherName){
                result.insert(child);
            }
        }
        for(auto & child : all){
            if (child->FatherName == this->FatherName && child->MotherName != this -> MotherName){
                result.insert(child);
            }
        }
        return result;
    }

    std::cout << "wrong" << std::endl;
    return result;
}

 std::set<Person*> Person::sisters(PMod pmod , SMod smod ){
    std::set<Person*> result;
    std::set<Person*> all;



    if (fatherN()!="???" &&Father->children().size()!=0){
        // std::cout << "running" <<std::endl;
        for (auto & child: Father->Children){
            if (child->gender() == Gender::FEMALE&&child->name ()!= Name){
                all.insert(child);
            }
        }
    }

    if (motherN()!="???" &&Mother->children().size()!=0){
        // std::cout << "running" <<std::endl;
        for (auto & child: Mother->Children){
            if (child->gender() == Gender::FEMALE && child->name() != Name){
                all.insert(child);
            }
        }
    }


    // for (auto & child: Father->Children){
    //     if (child->gender() == Gender::FEMALE&&child->name ()!= Name){
    //         all.insert(child);
    //     }
    // }
    
    if (pmod == PMod::ANY && smod == SMod::ANY){
        return all;
    }
    if (pmod == PMod::PATERNAL && smod == SMod::HALF){
        for(auto & child : all){
            if (child->FatherName == this->FatherName && child->MotherName != this->MotherName){
                result.insert(child);
            }
        }
        return result;
    }
    if(pmod == PMod::PATERNAL && smod == SMod::ANY){
        for(auto & child : all){
            if (child->FatherName == this->FatherName){
                result.insert(child);
            }
        }
        return result;
    }
    if (pmod == PMod::MATERNAL && smod == SMod::HALF){
        for(auto & child : all){
            if (child->FatherName != this->FatherName && child->MotherName == this->MotherName){
                result.insert(child);
            }
        }
        return result;
    }
    if(pmod == PMod::MATERNAL && smod == SMod::ANY){
        for(auto & child : all){
            if (child->MotherName == this->MotherName){
                result.insert(child);
            }
        }
        return result;
    }

    if (pmod == PMod::ANY && smod == SMod::HALF){
        for(auto & child : all){
            if (child->FatherName != this->FatherName && child->MotherName == this->MotherName){
                result.insert(child);
            }
        }
        for(auto & child : all){
            if (child->FatherName == this->FatherName && child->MotherName != this->MotherName){
                result.insert(child);
            }
        }
        return result;
    }


    if (pmod == PMod::ANY && smod == SMod::FULL){
        if (mother()==nullptr || father() == nullptr){
            return result;
        }
        for(auto & child : all){
            if (child->FatherName == this->FatherName && child->MotherName == this->MotherName){
                result.insert(child);
            }
        }
        return result;
    }
    if (pmod == PMod::PATERNAL && smod == SMod::FULL){
        if (father()==nullptr){
            return result;
        }
        for(auto & child : all){
            if (child->FatherName == this->FatherName && child->MotherName == this->MotherName){
                result.insert(child);
            }
        }
        return result;
    }
    if (pmod == PMod::MATERNAL && smod == SMod::FULL){
        if (mother() == nullptr){
            return result;
        }
        for(auto & child : all){
            if (child->FatherName == this->FatherName && child->MotherName == this->MotherName){
                result.insert(child);
            }
        }
        return result;
    }

    std::cout << "wrong" << std::endl;
    return result;
 }

std::set<Person*> Person::children(){

    return this->Children;
}


std::set<Person*> Person::daughters(){
    std::set<Person*> result;
    for(auto & child: Children){
        if(child->gender() == Gender::FEMALE){
            result.insert(child);
        }
    }
    return result;
}

std::set<Person*> Person::sons(){
    std::set<Person*> result;
    for(auto & child: Children){
        if(child->gender() == Gender::MALE){
            result.insert(child);
        }
    }
    return result;
}

std::set<Person*> Person::grandchildren(){
    std::set<Person*> result;
    for(auto & child: Children){
        for (auto & grandchild: child->Children){
            result.insert(grandchild);
        }
    }
    return result;
}

std::set<Person*> Person::granddaughters(){
    std::set<Person*> result;
    for (auto & grandd : grandchildren()){
        if (grandd->gender()==Gender::FEMALE){
            result.insert(grandd);
        }
    }
    return result;
}

std::set<Person*> Person::grandsons(){
    std::set<Person*> result;
    for (auto & grands: grandchildren()){
        if (grands->gender() == Gender::MALE){
            result.insert(grands);
        }
    }
    return result;
}

std::set<Person*> Person::grandparents(PMod pmod ){
    std::set<Person*> result;
    if (pmod == PMod::MATERNAL){
        for(auto & grand: Mother->parents()){
            result.insert(grand);
        }
    }
    else if (pmod == PMod::PATERNAL){
        for(auto & grand: Father->parents()){
            result.insert(grand);
        }
    }
    else{
        for(auto & grand: Mother->parents()){
            result.insert(grand);
        }
        for(auto & grand: Father->parents()){
            result.insert(grand);
        }
    }
    return result;
}

std::set<Person*> Person::parents(PMod pmod ){
    std::set<Person*> result;
    
    if (pmod == PMod::MATERNAL){
        if (Mother!=nullptr){
            result.insert(Mother);
        }
    }
    else if(pmod == PMod::PATERNAL){
        if (Father!=nullptr){
            result.insert(Father);
        }
    }
    else {
        if (Mother!=nullptr){
            result.insert(Mother);
        }
        if (Father!=nullptr){
            result.insert(Father);
        }
    }

    return result;
}

std::set<Person*> Person::grandmothers(PMod pmod ){
    std::set<Person*> result;
    if (pmod == PMod::MATERNAL){
        result.insert(Mother->Mother);
    }
    else if (pmod == PMod::PATERNAL){
        result.insert(Father->Mother);
    }
    else {
        result.insert(Mother->Mother);
        result.insert(Father->Mother);
    }


    return result;
}

std::set<Person*> Person::grandfathers(PMod pmod ){
    std::set<Person*> result;
    if (pmod == PMod::MATERNAL){
        result.insert(Mother->Father);
    }
    else if (pmod == PMod::PATERNAL){
        result.insert(Father->Father);
    }
    else {
        result.insert(Mother->Father);
        result.insert(Father->Father);
    }


    return result;
}

std::set<Person*> Person::aunts(PMod pmod, SMod smod ){
    std::set<Person*> result;
    if(pmod == PMod::ANY && smod == SMod::ANY){
        for(auto & aunt: Mother->sisters()){
            result.insert(aunt);
        }
        for(auto & aunt: Father->sisters()){
            result.insert(aunt);
        }
        return result;
    }
    if (pmod == PMod::MATERNAL && smod == SMod::ANY){
        for(auto & aunt: Mother->sisters()){
            result.insert(aunt);
        }
        return result;
    }
    if (pmod == PMod::PATERNAL && smod == SMod::ANY){
        for(auto & aunt: Father->sisters()){
            result.insert(aunt);
        }
        return result;
    }
    if (pmod == PMod::ANY && smod == SMod::FULL){
        for(auto & aunt: Father->sisters(PMod::ANY,SMod::FULL)){
            result.insert(aunt);
        }
        for(auto & aunt: Mother->sisters(PMod::ANY,SMod::FULL)){
            result.insert(aunt);
        }
        return result;
    }
    if (pmod == PMod::ANY && smod == SMod::HALF){
        for(auto & aunt: Father->sisters(PMod::ANY,SMod::HALF)){
            result.insert(aunt);
        }
        for(auto & aunt: Mother->sisters(PMod::ANY,SMod::HALF)){
            result.insert(aunt);
        }
        return result;
    }
    if (pmod == PMod::MATERNAL && smod == SMod::HALF){
        for(auto & aunt: Mother->sisters(PMod::ANY,SMod::HALF)){
            result.insert(aunt);
        }
        return result;
    }
    if (pmod == PMod::MATERNAL && smod == SMod::FULL){
        for(auto & aunt: Mother->sisters(PMod::ANY,SMod::FULL)){
            result.insert(aunt);
        }
        return result;
    }
    if (pmod == PMod::PATERNAL && smod == SMod::HALF){
        for(auto & aunt: Father->sisters(PMod::ANY,SMod::HALF)){
            result.insert(aunt);
        }
        return result;
    }
    if (pmod == PMod::PATERNAL && smod == SMod::FULL){
        for(auto & aunt: Father->sisters(PMod::ANY,SMod::FULL)){
            result.insert(aunt);
        }
        return result;
    }

    std::cout << "WRONG" << std::endl;
    return result;
}

std::set<Person*> Person::uncles(PMod pmod, SMod smod){
    std::set<Person*> result;

    if(pmod == PMod::ANY && smod == SMod::ANY){
        for(auto & uncle: Mother->brothers()){
            result.insert(uncle);
        }
        for(auto & uncle: Father->brothers()){
            result.insert(uncle);
        }
        return result;
    }
    if (pmod == PMod::MATERNAL && smod == SMod::ANY){
        for(auto & uncle: Mother->brothers()){
            result.insert(uncle);
        }
        return result;
    }
    if (pmod == PMod::PATERNAL && smod == SMod::ANY){
        for(auto & uncle: Father->brothers()){
            result.insert(uncle);
        }
        return result;
    }
    if (pmod == PMod::ANY && smod == SMod::FULL){
        for(auto & uncle: Father->brothers(PMod::ANY,SMod::FULL)){
            result.insert(uncle);
        }
        for(auto & uncle: Mother->brothers(PMod::ANY,SMod::FULL)){
            result.insert(uncle);
        }
        return result;
    }
    if (pmod == PMod::ANY && smod == SMod::HALF){
        for(auto & uncle: Father->brothers(PMod::ANY,SMod::HALF)){
            result.insert(uncle);
        }
        for(auto & uncle: Mother->brothers(PMod::ANY,SMod::HALF)){
            result.insert(uncle);
        }
        return result;
    }
    if (pmod == PMod::MATERNAL && smod == SMod::HALF){
        for(auto & uncle: Mother->brothers(PMod::ANY,SMod::HALF)){
            result.insert(uncle);
        }
        return result;
    }
    if (pmod == PMod::MATERNAL && smod == SMod::FULL){
        for(auto & uncle: Mother->brothers(PMod::ANY,SMod::FULL)){
            result.insert(uncle);
        }
        return result;
    }
    if (pmod == PMod::PATERNAL && smod == SMod::HALF){
        for(auto & uncle: Father->brothers(PMod::ANY,SMod::HALF)){
            result.insert(uncle);
        }
        return result;
    }
    if (pmod == PMod::PATERNAL && smod == SMod::FULL){
        for(auto & uncle: Father->brothers(PMod::ANY,SMod::FULL)){
            result.insert(uncle);
        }
        return result;
    }

    std::cout << "WRONG" << std::endl;
    return result;

}

std::set<Person*> Person::cousins(PMod pmod, SMod smod){
    std::set<Person*> result;
    for (auto & unc: uncles(pmod,smod)){
        for (auto & cousin: unc->children()){
            result.insert(cousin);
        }
    }
    for (auto & aun: aunts(pmod,smod)){
        for (auto & cousin: aun->children()){
            result.insert(cousin);
        }
    }
    return result;
}

std::set<Person*> Person::siblings(PMod pmod , SMod smod ){
    std::set<Person*> result;
    for (auto & sister: sisters(pmod,smod)){
        result.insert(sister);
    }
    for (auto & brother: brothers(pmod,smod)){
        result.insert(brother);
    }
    return result;
}

std::set<Person*> Person::nephews(PMod pmod, SMod smod){
    std::set<Person*> result;
    for (auto & brother: brothers(pmod,smod)){
        for(auto & nephew: brother->children()){
            if (nephew->gender()==Gender::MALE){
                result.insert(nephew);
            }
        }
    }
    for (auto & sister: sisters(pmod,smod)){
        for(auto & nephew: sister->children()){
            if (nephew->gender()==Gender::MALE){
                result.insert(nephew);
            }
        }
    }
    return result; 
}

std::set<Person*> Person::nieces(PMod pmod, SMod smod ){
    std::set<Person*> result;
    for (auto & brother: brothers(pmod,smod)){
        for (auto & niece: brother->children()){
            if (niece->gender()==Gender::FEMALE){
                result.insert(niece);
            }
        }  
    }

    for (auto & sister: sisters(pmod,smod)){
        for (auto & niece: sister->children()){
            if (niece->gender()==Gender::FEMALE){
                result.insert(niece);
            }
        } 
    }
    return result;
}


std::set<Person*> Person::addD(Person* root, std::set<Person*> result){
    if(root->children().size()==0){
        return result;
    }
    
    
    for(auto & child: root->children()){
        result.insert(child);
        for(auto & grandchild: addD(child,result)){
            result.insert(grandchild);
        }
    }

    return result;

}
std::set<Person*> Person::descendants(){
    std::set<Person*> result;
    Person *root;
    if (children().size()==0){
        return result;
    }

    for (auto & child: children()){
        if (Name== child->fatherN()){
            root = child->father();
            break;
        }
        else{
            root= child->mother();
            break;
        }
    }

    for (auto & des: addD(root,result)){
        result.insert(des);
    }
    return result;
}