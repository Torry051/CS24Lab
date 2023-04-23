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
    // b >> a;
    // int c;
    
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