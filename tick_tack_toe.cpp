#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  -----" << endl;
    }
}

// Function to check if there's a winner
char checkWinner(const vector<vector<char>>& board) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }
    // Check columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return board[0][j];
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }
    return ' '; // No winner yet
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize empty board
    char currentPlayer = 'X';
    bool gameover = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (!gameover) {
        // Print board
        printBoard(board);

        // Get player input
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row column): ";
        cin >> row >> col;
        row--; // Adjust for 0-based indexing
        col--; // Adjust for 0-based indexing

        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Update board
        board[row][col] = currentPlayer;

        // Check for a win
        char winner = checkWinner(board);
        if (winner != ' ') {
            printBoard(board);
            cout << "Player " << winner << " wins!" << endl;
            gameover = true;
        } else {
            // Check for a draw
            bool draw = true;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (board[i][j] == ' ') {
                        draw = false;
                        break;
                    }
                }
                if (!draw) break;
            }
            if (draw) {
                printBoard(board);
                cout << "It's a draw!" << endl;
                gameover = true;
            } else {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
    }

    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        main(); // Restart the game
    }

    return 0;
}
