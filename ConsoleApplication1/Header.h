#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <utility>
#include<sstream>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

class TicTacToe {
public:
    TicTacToe();
    void runGame(bool playWithAI);
private:
    string gameBoard[ROWS][COLS];
    set<pair<int, int>> availableMoves;
    void initializeGameBoard();
    void printCurrentBoard();
    void getUserInput(bool xTurn);
    bool cellAlreadyOccupied(int row, int col);
    string getWinner();
    bool isBoardFull();
    int evaluateBoard();
    int minimax(bool isMax);
    pair<int, int> findBestMove();
    string getColoredCell(const string& cell);
};

#endif
#pragma once
