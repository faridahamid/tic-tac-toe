//Write a program that uses a 2D array to represent a tic-tac-toe board. Allow two players to take turns entering their moves, and check for win conditions after each move.
#include <iostream>
using namespace std;

const int game_size= 3;

char board[game_size][game_size];

void initializeBoard() {//intialize the board of game to empty spaces
    for (int i = 0; i < game_size; i++) {
        for (int j = 0; j < game_size; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {//function which cout the board with empty spaces
    for (int i = 0; i < game_size; i++) {
        for (int j = 0; j < game_size; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValidMove(int row, int col) {//checks row and column are within the board boundaries and if the corresponding cell is empty.
    if (row < 0 || row >=game_size || col < 0 || col >= game_size) {
        return false;
    }

    if (board[row][col] != ' ') {
        return false;
    }

    return true;
}

bool isWin(char player) {
    // Check row
    for (int i = 0; i < game_size; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check col
    for (int j = 0; j < game_size; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    // Check diag
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool isBoardFull() {
    for (int i = 0; i < game_size; i++) {
        for (int j = 0; j < game_size; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void playGame() {
    char currentPlayer = 'X';

    while (true) {
        displayBoard();

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move  ";
        cin >> row >> col;

        if (isValidMove(row, col)) {
            board[row][col] = currentPlayer;

            if (isWin(currentPlayer)) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            } else if (isBoardFull()) {
                displayBoard();
                cout << "It's a draw!" << endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

int main() {
    initializeBoard();
    playGame();

    return 0;
}

				


   
