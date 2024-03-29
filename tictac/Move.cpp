#include "Errors.h"
#include "Move.h"

#include <iostream>
#include <sstream>
#include <cctype>

// Space for implementing Move functions.

Move::Move(const std::string& input) {
    // if (!format(input)) {
    //     throw ParseError("error");
    // }
    std::istringstream inf(input);
    std::string location;
    std::string num;

    
 

    if (input.size() < 6) {
        throw ParseError("error 1");
    }
    if (input[0]<'1'||input[0]>'9'){
        throw ParseError("error");
    }

    unsigned index = 0;
    for (unsigned i=0; i < input.size(); i++) {
        if (input[i]=='x'||input[i] =='X'||input[i]=='O' || input[i]=='o') {
            index = i;
            // std::cout<< index  << std::endl;
            break;
        }
    }
    
    if (input.size()-1<index+3){
        throw ParseError("error 3");
    }

    // std::cout<< index << " " << input.size() << std::endl;
    if (index!=0) {
        if (!isspace(input[index-1]) || !isspace(input[index+1])) { 
            throw ParseError("error 2");
        }
    }
    else {
        throw ParseError("error 4");
    }



    inf >> num;
    number = stoi(num);
    if (number <1  || number > 9){
        throw ParseError("number error");
    }
    if (inf.fail()) {
        throw ParseError("number input error");
    }

    // std::string str;
    // inf >> str;
    // if (str.size()!= 1) {
    //     throw ParseError("space error");
    // }
    // player = str[0];
    // std::cout << player << std::endl;
    inf >> player;
    if (inf.fail()) {
        throw ParseError("player input error");
    }
    if (player!='x' && player!='X' && player!='o' && player != 'O') {
        throw ParseError("player error");
    } 

    inf >> location; 
    if (inf.fail()) {
        throw ParseError(" row and column error");
    }
    if (location.size()!=2) {
        throw ParseError(" row and column error");
    }
    
    char r = location[0];
    char * c = &location[1];

    if (r!='A' && r!='B'&& r!='C'&& r!='a'&& r!='b'&& r!='c') {
        throw ParseError("row error");
    }
    column = atoi(c);
    // std::cout << number << std::endl;
    row = static_cast<int>(r);
    if (column<1 || column >3) {
        throw ParseError("column error");
    }
    com = false;

    if (!inf.eof()) {
        inf >> comment;
        if (!inf.fail()){
            if (comment[0]!='#'){
                throw ParseError("comment error");
            }
        }
    }

    // unsigned index2 = 0;
    // for (unsigned i=0; i<input.size();i++ ){
    //     if (input[i]=='1'||input[i]=='2'||input[i]=='3'){
    //         index2 = i;
    //     }
    // }
    // if (index2 == 0) {
    //     throw ParseError("error");
    // }
    // if (!inf.eof()){
    //     for (unsigned i=index2; i<input.size();i++) {
    //         if (input[i] == '#'){
    //             com = true;
    //         }
    //     }
    //     if (com == true) {
    //         inf >> comment;
    //         if (inf.fail()) {
    //             // throw ParseError("comment error 1");
    //         }
    //         if (comment[0]!= '#') {
    //             // throw ParseError("comment error");
    //         }
    //     }
    //     else {
    //         for (unsigned i = index2; i<input.size();i++){
    //             if (input[i]!= ' '){
    //                 throw ParseError("error 6");
    //             }
    //         }
    //     }
       
    // }

}


std::ostream& operator << (std::ostream& stream, const Move& move) {
    char p,r;
    stream << move.number << " ";
    if(move.player == 'x'||move.player=='o'){
        p = move.player - 32;
    }
    else {
        p = move.player;
    }
    stream << p << " ";
    
    if (move.row >= 97) {
        r = move.row - 32;
    }
    else {
        r = move.row - 0;
    }

    stream << r << move.column;


    // if (move.com == true) {
    //     stream << " " << move.comment;
    // }

    return stream;


}
