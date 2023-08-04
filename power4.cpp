#include <iostream>

const int ROWS = 6;
const int COLS = 7;
const char EMPTY = '|';

class Power4Game {
private:
    char board[ROWS][COLS];
    int currentPlayer;

public:
    Power4Game() : currentPlayer(1) {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                board[i][j] = EMPTY;
            }
        }
    }

    void printBoard() {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool dropPiece(int col) {
        if (col < 0 || col >= COLS) {
            std::cout << "Invalid column. Please choose a column between 0 and " << COLS - 1 << "." << std::endl;
            return false;
        }
         
       for (int i = ROWS - 1; i >= 0; --i) {
      // for (int i = 0; i <= ROWS-1; i++) {
            if (board[i][col] == EMPTY) {
                board[i][col] = currentPlayer == 1 ? 'X' : 'O';
                return true;
            }
        }

        std::cout << "Column " << col << " is full. Please choose another column." << std::endl;
        return false;
    }

    bool checkWin() {
    // Check for horizontal win
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (board[i][j] != EMPTY && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3]) {
                return true;
            }

        }
    }

    // Check for vertical win
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (board[i][j] != EMPTY &&
                board[i][j] == board[i + 1][j] &&
                board[i][j] == board[i + 2][j] &&
                board[i][j] == board[i + 3][j]) {
                return true;
            }
        }
    }

    // Check for diagonal win (left to right)
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (board[i][j] != EMPTY &&
                board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2] &&
                board[i][j] == board[i + 3][j + 3]) {
                return true;
            }
        }
    }

    // Check for diagonal win (right to left)
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 3; j < COLS; ++j) {
            if (board[i][j] != EMPTY &&
                board[i][j] == board[i + 1][j - 1] &&
                board[i][j] == board[i + 2][j - 2] &&
                board[i][j] == board[i + 3][j - 3]) {
                return true;
            }
        }
    }

    return false;
}


    void switchPlayer() {
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    int getCurrentPlayer() const {
        return currentPlayer;
    }
};

int main() {
    Power4Game game;
    int col;

    std::cout << "Welcome to Power4!" << std::endl;

    while (true) {
        game.printBoard();

        std::cout << "Player " << game.getCurrentPlayer() << ", enter the column (0-" << COLS - 1 << ") to drop your piece: ";
        std::cin >> col;

        if (game.dropPiece(col)) {
            if (game.checkWin()) {
                game.printBoard();
                std::cout << "Player " << game.getCurrentPlayer() << " wins!" << std::endl;
                break;
            }
            game.switchPlayer();
        }
    }

    return 0;
}

