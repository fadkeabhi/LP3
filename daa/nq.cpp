#include <iostream>
#include <vector>

#define N 8

void printSolution(std::vector<std::vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool isSafe(std::vector<std::vector<int>>& board, int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

bool solveNQUtil(std::vector<std::vector<int>>& board, int col) {
    if (col >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1)) {
                return true;
            }

            board[i][col] = 0;
        }
    }

    return false;
}

bool solveNQ() {
    std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));

    // Place the first queen at a specific position, e.g., (0, 0)
    board[0][0] = 1;

    if (!solveNQUtil(board, 1)) {
        std::cout << "Solution does not exist" << std::endl;
        return false;
    }

    printSolution(board);
    return true;
}

int main() {
    solveNQ();
    return 0;
}