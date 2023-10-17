#include <iostream>
#include <vector>
using namespace std;


void displayBoard(const vector<vector<char>>& board) {
    for (const vector<char>& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}


bool checkWin(const vector<vector<char>>& board, char player) {
    
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;  
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;  
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;  
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; 
    }
    return false;
}


bool checkDraw(const vector<vector<char>>& board) {
    for (const vector<char>& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;  
            }
        }
    }
    return true;  
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    bool gameOver = false;

    while (!gameOver) {
        cout << "Current board:" << endl;
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column, e.g., 1 2): ";
        cin >> row >> col;

    
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        
        board[row - 1][col - 1] = currentPlayer;

    
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        } else if (checkDraw(board)) {
            cout << "It's a draw!" << endl;
            gameOver = true;
        } else {
        
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    cout << "Game over. Play again? (y/n): ";
    char playAgain;
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        gameOver = false;
    } else {
        cout << "Thanks for playing!" << endl;
    }

    return 0;
}
