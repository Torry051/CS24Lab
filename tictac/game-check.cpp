#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>



int main() {
    std::string line;
    
    
    try {
        Board board;
        std::cout << "> ";
        getline(std::cin,line);
        while (!std::cin.eof()) {
            if (!board.game_over()) {
                Move new_move(line);
                board.play(new_move);
                std::cout << "> ";
                getline(std::cin,line);  
            }
            else {
                break;
            }
        }
        board.game_result();
        return 0;
    }
    catch (const ParseError erro) {
        std::cout << "Parse error. " << erro.what() << std::endl;
        return 1;
    }
    catch (const InvalidMove erro) {
        std::cout << "Invalid move. " << erro.what() << std::endl;
        return 2;
    }
    
}
