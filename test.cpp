#include <iostream>
using namespace std;

void printBoard(char* board, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << " | " << board[i * col + j] << " | ";
        }
        cout << "\n";
    }
}

void selectValidMove(char* board, int row, int col, char sym, int& m, int& n) {
    cout << "Select a row and column to make a move: ";
    cin >> m >> n;

    if (m <= row && n <= col && board[(m - 1) * col + (n - 1)] == '*') {
        board[(m - 1) * col + (n - 1)] = sym;
    } else {
        cout << "Invalid move. Try again.\n";
        selectValidMove(board, row, col, sym, m, n); // Recursive call
    }
}

bool checkWin(char* board, int row, int col, int m, int n, char sym) {
    return ((n - 2 >= 0 && board[(m - 1) * col + (n - 2)] == sym && board[(m - 1) * col + (n - 3)] == sym) || // Left
            (n + 2 < col && board[(m - 1) * col + (n)] == sym && board[(m - 1) * col + (n + 1)] == sym) || // Right
            (m - 2 >= 0 && board[(m - 2) * col + (n - 1)] == sym && board[(m - 3) * col + (n - 1)] == sym) || // Up
            (m + 2 < row && board[(m) * col + (n - 1)] == sym && board[(m + 1) * col + (n - 1)] == sym) || // Down
            (m - 2 >= 0 && n - 2 >= 0 && board[(m - 2) * col + (n - 2)] == sym && board[(m - 3) * col + (n - 3)] == sym) || // Top-left
            (m + 2 < row && n + 2 < col && board[(m) * col + (n)] == sym && board[(m + 1) * col + (n + 1)] == sym) || // Bottom-right
            (m - 2 >= 0 && n + 2 < col && board[(m - 2) * col + (n)] == sym && board[(m - 3) * col + (n + 1)] == sym) || // Top-right
            (m + 2 < row && n - 2 >= 0 && board[(m) * col + (n - 2)] == sym && board[(m + 1) * col + (n - 3)] == sym)); // Bottom-left
}

bool checkDraw(char* board, int row, int col) {
    for (int i = 0; i < row * col; i++) {
        if (board[i] == '*') return false;
    }
    return true;
}

int main() {
    int players;
    do {
        cout << "Enter the number of players between 2 and 5: ";
        cin >> players;
    } while (players < 2 || players > 5);

    char sym[5] = { 'X', 'O', '#', '$', '&' };
    for (int i = 0; i < players; i++) {
        cout << "\nPlayer " << (i + 1) << " : " << sym[i] << "\n";
    }

    int row, col;
    do {
        cout << "\nEnter number of columns and rows (minimum 3x3): ";
        cin >> row >> col;
    } while (row < 3 || col < 3);

    char* board = new char[row * col];
    fill(board, board + (row * col), '*');
    printBoard(board, row, col);

    int m, n;
    while (true) {
        for (int i = 0; i < players; i++) {
            cout << "\nPlayer " << (i + 1) << "'s turn (Symbol: " << sym[i] << ")\n";
            selectValidMove(board, row, col, sym[i], m, n);
            printBoard(board, row, col);

            if (checkWin(board, row, col, m, n, sym[i])) {
                cout << "Player " << (i + 1) << " with symbol " << sym[i] << " has won!!\n";
                delete[] board;
                return 0;
            }
            
            if (checkDraw(board, row, col)) {
                cout << "The match is Draw!!\n";
                delete[] board;
                return 0;
            }
        }
    }
}

