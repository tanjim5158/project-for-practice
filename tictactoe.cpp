#include <iostream>
using namespace std;

char board[3][3];

void initializeBoard() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}


void displayBoard() {

    cout << "\n";

    for (int i = 0; i < 3; i++) {

        cout << " " << board[i][0]
             << " | " << board[i][1]
             << " | " << board[i][2] << "\n";

        if (i < 2) {
            cout << "---|---|---\n";
        }
    }

    cout << "\n";
}


void playerMove(char player) {

    int row, col;

    while (true) {

        cout << "Player " << player
             << ", enter row and column (1-3): ";

        cin >> row >> col;

        row--;
        col--;

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "Invalid position! Try again.\n";
        }

        else if (board[row][col] != ' ') {
            cout << "That position is already occupied! Try again.\n";
        }

        else {
            board[row][col] = player;
            break;
        }
    }
}


bool checkWinner(char player) {

    for (int i = 0; i < 3; i++) {

        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player) {

            return true;
        }
    }


    for (int j = 0; j < 3; j++) {

        if (board[0][j] == player &&
            board[1][j] == player &&
            board[2][j] == player) {

            return true;
        }
    }


    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player) {

        return true;
    }


    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player) {

        return true;
    }


    return false;
}


bool isDraw() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}


int main() {

    initializeBoard();

    char player = 'X';


    while (true) {

        displayBoard();


        playerMove(player);


        if (checkWinner(player)) {

            displayBoard();

            cout << "Player " << player << " wins!\n";

            break;
        }


        if (isDraw()) {

            displayBoard();

            cout << "It's a draw!\n";

            break;
        }


        if (player == 'X') {
            player = 'O';
        }
        else {
            player = 'X';
        }
    }


    return 0;
}

