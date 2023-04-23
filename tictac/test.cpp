# include "Move.h"
# include <iostream>
# include <string>
# include <sstream>


int main() {
    // std::string input;

    // std::getline(std::cin,input);
    // Move a(input);

    // std::istringstream b("1 X C3");
    // std::string a;
    // char ab;
    // std::string abc;
    // int c;
    // b >> a;
    // if (b.fail()) {
    //     std::cout << "report" << std::endl;
    //     return 1;
    // }


    // b >> ab;
    // if (b.fail()) {
    //     std::cout << "report" << std::endl;
    //     return 1;
    // }
    

    // b >> abc;
    // if (b.fail()) {
    //     std::cout << "report" << std::endl;
    //     return 1;
    // }
    // char * o = &abc[0];

    // c = *o;
    // std::cout << c << std::endl;



    
    // c = stoi(a);
    // std::cout << c << std::endl;


    std::string input("1 o c3 #qweq");
    Move a(input);
    std::cout << a.number << " " <<  a.player << " " << a.row  << " " <<a.column<< std::endl;
    std::cout << a << std::endl; 
    // std::cout << input.size() << std::endl;
    // if(format(input)) {
    //     std::cout << "yes" << std::endl;
    // }
    // else {
    //     std::cout << "no" << std::endl;
    // }
    return 0;
}