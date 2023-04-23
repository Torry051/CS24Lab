# include "Move.h"
# include <iostream>
# include <string>


int main() {
    // std::string input;

    // std::getline(std::cin,input);
    // Move a(input);

    // char a = 97 - 32;
    // std::cout<<a<<std::endl;
    // string test('1sad');
    // int num(test);
    // std::cout << num << std::endl;
    std::string input("2 X b3#we");
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