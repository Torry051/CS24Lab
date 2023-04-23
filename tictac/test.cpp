# include "Move.h"
# include <iostream>
# include <string>
# include <sstream>


int main() {
    // std::string input;

    // std::getline(std::cin,input);
    // Move a(input);

    // std::istringstream b("2 X C3");
    // int a;
    // b >> a;
    // a = a -1 ;
    // std::cout << a << std::endl;


    std::string input("1 o q3 #qweq");
    Move a(input);
    // std::cout << a.number << " " <<  a.player << " " << a.row  << " " <<a.column<< std::endl;
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