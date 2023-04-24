#include "Errors.h"
#include "Board.h"
#include <iostream>

// Space for implementing Board functions.
Board::Board() {
    rounds = 0;
    turn = ' ';
    for (int i = 0; i < 3; i++) {
        for (int j=0; j<3; j++) {
            arr[i][j] = 0;
        }
    }
}

char Board::winner() {
    if (arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2] && arr[0][0]!=0) {
        if (arr[0][0] == 1) {
            return 'X';
        }
        else {
            return 'O';
        }
    }
    else if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2] && arr[1][0]!=0) {
        if (arr[1][0] == 1) {
            return 'X';
        }
        else {
            return 'O';
        }
    }
    else if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2] && arr[2][0]!=0) {
        if (arr[2][0] == 1) {
            return 'X';
        }
        else {
            return 'O';
        }
    }
    else if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0] && arr[0][0]!=0) {
        if (arr[0][0] == 1) {
            return 'X';
        }
        else {
            return 'O';
        }
    }
    else if (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1] && arr[0][1]!=0) {
        if (arr[0][1] == 1) {
            return 'X';
        }
        else {
            return 'O';
        }
    }
    else if (arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2] && arr[0][2]!=0) {
        if (arr[0][2] == 1) {
            return 'X';
        }
        else {
            return 'O';
        }
    }
    else if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0]!=0) {
        if (arr[0][0] == 1) {
            return 'X';
        }
        else {
            return 'O';
        }
    }
    else if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0] && arr[0][2]!=0) {
        if (arr[0][0] == 1) {
            return 'X';
        }
        else {
            return 'O';
        }
    }
    else {
        return 'N';
    }

}

void Board::play(const Move & move) {
    if (rounds == 0) {
        turn = move.player;
    }
    else if (rounds == 9) {
        throw InvalidMove("turn error");
    }
    else if (winner() != 'N'){
        throw InvalidMove("winner error");
    }
    else {
        if (turn == move.player) {
            throw InvalidMove("turn error");
        }
        else {
            turn = move.player;
        }
    }
    
    rounds = rounds + 1;
    if (move.number != rounds) {
        throw InvalidMove("round error");
    }

    int ro = move.row - '@';
    if (arr[ro-1][move.column-1] != 0) {
        // std::cout << ro << " " << move.column << " " << arr[ro][move.column] << std::endl;
        throw InvalidMove("location error");
    }

    if (move.player == 'x'||move.player=='X'){
        arr[ro-1][move.column-1] = 1;
    }
    else if (move.player == 'o'||move.player=='O'){
        arr[ro-1][move.column-1] = 2;
    }
    else { //test 
        std::cout << "?" << std::endl;
    }

}

bool Board::game_over() {
    if(rounds == 9) {
        return true;
    }
    if(this->winner()== 'X' || this->winner()=='O'){
        return true;
    }

    return false;
}

void Board::game_result() {
    if (game_over()) {
        if (winner() == 'X'){
            std::cout << "Game over: X wins." << std::endl;
        }
        else if (winner() == 'O'){
            std::cout << "Game over: O wins." << std::endl;
        }
        else {
            std::cout << "Game over: Draw." << std::endl;
        }
    }
    else {
        if (rounds== 0) {
            std::cout << "Game in progress: New game." << std::endl;
        }
        else {
            if (turn == 'X'||turn == 'x'){
                std::cout<<"Game in progress: O's turn" << std::endl;
            }
            else {
                std::cout<<"Game in progress: X's turn" << std::endl;
            }
        }
    }
}