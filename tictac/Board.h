#ifndef BOARD_H
#define BOARD_H

#include "Move.h"

// I recommended writing a Board class to manage your game state.
// Here's some space for the class definition; member functions go in Board.cpp.

class Board {
    int rounds;
    char turn;
    int arr[3][3];
    
public:
    Board();
    char winner();
    void play(const Move & move);
    void game_result();
    bool game_over();
};

#endif
