#include "Person.h"
#include "GenePool.h"

#include <istream>
#include <set>
#include <string>
#include <map>
#include <fstream>
#include <iostream>

int main(int argc, char** argv) {

    std::ifstream stream(argv[1]);
    GenePool pool(stream);
    // std::cout << pool.mymap["Fairy Bridge"]->name()  << std::endl;
    // std::cout << pool.mymap["Fairy Bridge"]->name()  << std::endl;
    // std::cout << pool.find("Danzig")->MotherName << "        " << pool.find("Danzig")->FatherName << std::endl;
    std::set<Person*> cdr(pool.mymap["Matti"]->brothers());
    // std::cout << "running" << std::endl;
    for (auto & ch: cdr){
        std::cout << ch->name() << std::endl;
    }

   
    // std::cout << pool.mymap["Fairy Bridge"]-> << std::endl;
    // std::cout << "runnign" <<std::endl;

}
