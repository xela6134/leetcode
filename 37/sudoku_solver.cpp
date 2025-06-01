#include <iostream>
#include <vector>

bool solve(std::vector<std::vector<char>>& board) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] != '.') continue;

            for (char digit = '1'; digit <= '9'; ++digit) {
                if (isValid(board, row, col, digit)) {
                    board[row][col] = digit;
                    if (solve(board)) return true;
                    board[row][col] = '.';              // backtrack
                }
            }
            return false;
        }
    }
    return true;
}

bool isValid(std::vector<std::vector<char>>& board, int row, int col, char digit) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == digit) return false;           // check row
        if (board[i][col] == digit) return false;           // check column
        int boxRow = 3 * (row / 3) + i / 3;
        int boxCol = 3 * (col / 3) + i % 3;
        if (board[boxRow][boxCol] == digit) return false;   // check 3x3 box
    }
    return true;
}

void solveSudoku(std::vector<std::vector<char>>& board) {
    solve(board);
}

int main() {

}
