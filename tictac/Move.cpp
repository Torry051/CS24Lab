#include "Errors.h"
#include "Move.h"

#include <iostream>
#include <sstream>
#include <cctype>

// Space for implementing Move functions.

Move::Move(const std::string& input) {
    if (!format(input)) {
        throw ParseError("error");
    }

    // if (input.size() < 6) {
    //     throw ParseError("error");
    // }
    // if (!isspace(input[1]) || !isspace(input[3])) { 
    //     throw ParseError("error");
    // }

    std::istringstream inf(input);
    std::string location;

    inf >> number;
    if (inf.fail()) {
        throw ParseError("error");
    }

    inf >> player;
    inf >> location; 

    // std::cout << location << std::endl;
    if (com == true) {
        inf >> comment;
    }

    row = location[0];
    column = location[1]; 

}

bool Move::format(const std::string& input) {
    if (input.size() < 6) {
        return false;
    }
    if (input[0] < '1' ||input[0] > '9') {
        return false;
    }

    if (!isspace(input[1]) || !isspace(input[3])) { 
        return false;
    }
    if (input[2]!='X' && input[2]!='x'&& input[2]!='O'&& input[2]!='o'){
    // if (input[2]<'A'||(input[2]>'Z'&&input[2]<'a')||input[2]>'z') {
        // std::cout << "3" <<std::endl;
        return false;
    }
    if (input[4]!='A' && input[4]!='B'&& input[4]!='C'&& input[4]!='a'&&input[4]!='b'&& input[4]!='c'){
    // if (input[4]<'A'||(input[4]>'Z'&&input[4]<'a')||input[4]>'z') {
        // std::cout << "4" <<std::endl;
        return false;
    }
    if (input[5]!='1'&& input[5]!='2'&& input[5]!='3'){
    // if (input[0] < '1' ||input[0] > '9') {
        // std::cout << "5" <<std::endl;
        return false;
    }

    if (input.size()>6) {
        if (input[6]=='#') {
            return false;
        }
        else if (!isspace(input[6])) {
            return false;
        } 
        else {
            for (unsigned i = 7; i<input.size()-1; i++) {
                if (input[i] == '#') {
                    com = true;
                }
            }
        }

    } 

    return true;
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

    int c = move.column - 48;
    stream << r << c;


    if (move.com == true) {
        stream << " " << move.comment;
    }

    return stream;


}
