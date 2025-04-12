#include <iostream>
#include <vector>
#include <unordered_set>

bool isValidSudoku(std::vector<std::vector<char>>& board) {
    int SUDOKU_SIZE = 9;

    // Step 1: Check rows
    for (int i = 0; i < SUDOKU_SIZE; ++i) {
        std::unordered_set<char> seen;
        for (int j = 0; j < SUDOKU_SIZE; ++j) {
            char c = board[i][j];
            if (c == '.') continue;
            if (seen.find(c) != seen.end()) return false;
            seen.insert(c);
        }
    }

    // Step 2: Check columns
    for (int j = 0; j < SUDOKU_SIZE; ++j) {
        std::unordered_set<char> seen;
        for (int i = 0; i < SUDOKU_SIZE; ++i) {
            char c = board[i][j];
            if (c == '.') continue;
            if (seen.find(c) != seen.end()) return false;
            seen.insert(c);
        }
    }

    // Step 3: Check 3x3 sub-boxes
    for (int boxRow = 0; boxRow < 9; boxRow += 3) {
        for (int boxCol = 0; boxCol < 9; boxCol += 3) {
            std::unordered_set<char> seen;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    char c = board[boxRow + i][boxCol + j];
                    if (c == '.') continue;
                    if (seen.find(c) != seen.end()) return false;
                    seen.insert(c);
                }
            }
        }
    }

    return true;
}

int main() {

}
