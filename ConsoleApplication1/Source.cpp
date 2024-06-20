#include "Header.h"

TicTacToe::TicTacToe() {
    initializeGameBoard();
}

void TicTacToe::runGame(bool playWithAI) {
    string winner = "";  // empty string means no winner yet
    bool xTurn = true;
    initializeGameBoard();

    // Add all moves to the set of available moves
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            availableMoves.insert({ i, j });
        }
    }

    printCurrentBoard();

    while (winner == "") {  // game loop continues as long as no winner found
        if (xTurn) {
            cout << "It's X's turn" << (playWithAI ? " (You)" : "") << endl;
            getUserInput(xTurn);
        }
        else {
            if (playWithAI) {
                cout << "It's O's turn (AI)" << endl;
                pair<int, int> bestMove = findBestMove();
                gameBoard[bestMove.first][bestMove.second] = "O";
                availableMoves.erase(bestMove);
            }
            else {
                cout << "It's O's turn" << endl;
                getUserInput(xTurn);
            }
        }
        cout << endl;
        printCurrentBoard();  // updated board
        winner = getWinner();
        xTurn = !xTurn;  // flip turn after each move

        if (winner == "" && isBoardFull()) {
            winner = "C";  // game is a draw
        }
    }

    cout << endl;
    if (winner == "C") {
        cout << "Game is a draw" << endl;
    }
    else {
        cout << "The winner is " << winner << endl;
    }
    cout << endl;
}

void TicTacToe::initializeGameBoard() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            gameBoard[i][j] = " ";  // empty space
        }
    }
    availableMoves.clear();
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            availableMoves.insert({ i, j });
        }
    }
}

void TicTacToe::getUserInput(bool xTurn) {
    int row = -1;
    int col = -1;
    bool keepAsking = true;
    string input;

    while (keepAsking) {
        cout << "Enter row and column (0 1 2) separated by space: ";
        getline(cin, input);
        istringstream iss(input);

        if (!(iss >> row >> col)) {
            cout << "Invalid input format. Please enter numbers only." << endl;
            continue;
        }

        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            cout << "Invalid input. Row and column must be between 0 and 2." << endl;
        }
        else if (!cellAlreadyOccupied(row, col)) {
            keepAsking = false;
            availableMoves.erase({ row, col });  // remove the move from available moves
        }
        else {
            cout << "The cell is already occupied. Please try again." << endl;
        }
    }

    if (xTurn) {
        gameBoard[row][col] = "X";
    }
    else {
        gameBoard[row][col] = "O";
    }
}

// printing the board with better visualization
void TicTacToe::printCurrentBoard() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << " " << gameBoard[i][j];
            if (j < COLS - 1) cout << " |";
        }
        cout << endl;
        if (i < ROWS - 1) cout << "---|---|---" << endl;
    }
}

bool TicTacToe::cellAlreadyOccupied(int row, int col) {
    return gameBoard[row][col] != " ";  // non-space means occupied
}

string TicTacToe::getWinner() {
    for (int i = 0; i < ROWS; ++i) {
        if (gameBoard[i][0] != " " && gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]) {
            return gameBoard[i][0];  // horizontal
        }
    }

    for (int j = 0; j < COLS; ++j) {
        if (gameBoard[0][j] != " " && gameBoard[0][j] == gameBoard[1][j] && gameBoard[1][j] == gameBoard[2][j]) {
            return gameBoard[0][j];  // vertical
        }
    }

    if (gameBoard[0][0] != " " && gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) {
        return gameBoard[0][0];  // diagonal (upper left to bottom right)
    }

    if (gameBoard[2][0] != " " && gameBoard[2][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[0][2]) {
        return gameBoard[2][0];  // diagonal (lower left to upper right)
    }

    return "";  // no winner
}

bool TicTacToe::isBoardFull() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (gameBoard[i][j] == " ") {
                return false;
            }
        }
    }
    return true;
}

// Evaluation function for the minimax algorithm
int TicTacToe::evaluateBoard() {
    // Check rows for victory
    for (int row = 0; row < ROWS; row++) {
        if (gameBoard[row][0] == gameBoard[row][1] && gameBoard[row][1] == gameBoard[row][2]) {
            if (gameBoard[row][0] == "O")
                return +10;
            else if (gameBoard[row][0] == "X")
                return -10;
        }
    }

    // Check columns for victory
    for (int col = 0; col < COLS; col++) {
        if (gameBoard[0][col] == gameBoard[1][col] && gameBoard[1][col] == gameBoard[2][col]) {
            if (gameBoard[0][col] == "O")
                return +10;
            else if (gameBoard[0][col] == "X")
                return -10;
        }
    }

    // Check diagonals for victory
    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) {
        if (gameBoard[0][0] == "O")
            return +10;
        else if (gameBoard[0][0] == "X")
            return -10;
    }
    if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) {
        if (gameBoard[0][2] == "O")
            return +10;
        else if (gameBoard[0][2] == "X")
            return -10;
    }

    // No one has won
    return 0;
}

// Minimax algorithm to find the optimal move
int TicTacToe::minimax(bool isMax) {
    int score = evaluateBoard();

    // If AI has won the game, return the evaluated score
    if (score == 10)
        return score;

    // If Human has won the game, return the evaluated score
    if (score == -10)
        return score;

    // If no more moves and no winner then it is a tie
    if (isBoardFull())
        return 0;

    // If this maximizer's move
    if (isMax) {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                // Check if cell is empty
                if (gameBoard[i][j] == " ") {
                    // Make the move
                    gameBoard[i][j] = "O";

                    // Call minimax recursively and choose the maximum value
                    best = max(best, minimax(!isMax));

                    // Undo the move
                    gameBoard[i][j] = " ";
                }
            }
        }
        return best;
    }

    // If this minimizer's move
    else {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                // Check if cell is empty
                if (gameBoard[i][j] == " ") {
                    // Make the move
                    gameBoard[i][j] = "X";

                    // Call minimax recursively and choose the minimum value
                    best = min(best, minimax(!isMax));

                    // Undo the move
                    gameBoard[i][j] = " ";
                }
            }
        }
        return best;
    }
}

// Find the best possible move for the AI
pair<int, int> TicTacToe::findBestMove() {
    int bestVal = -1000;
    pair<int, int> bestMove = { -1, -1 };

    // Traverse all cells, evaluate minimax function for all empty cells
    // and return the cell with optimal value
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Check if cell is empty
            if (gameBoard[i][j] == " ") {
                // Make the move
                gameBoard[i][j] = "O";

                // Compute evaluation function for this move
                int moveVal = minimax(false);

                // Undo the move
                gameBoard[i][j] = " ";

                // If the value of the current move is more than the best value, update best
                if (moveVal > bestVal) {
                    bestMove = { i, j };
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}
