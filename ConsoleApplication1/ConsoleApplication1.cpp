#include "Header.h"

int main() {
    TicTacToe game;
    char mode;
    cout << "Choose game mode:\n";
    cout << "1. Player vs Player\n";
    cout << "2. Player vs AI\n";
    cout << "Enter 1 or 2: ";
    cin >> mode;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the newline character left in the input buffer

    if (mode == '1') {
        game.runGame(false);
    }
    else if (mode == '2') {
        game.runGame(true);
    }
    else {
        cout << "Invalid mode selected. Exiting.\n";
    }

    return 0;
}
