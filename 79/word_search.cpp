#include <vector>
#include <string>
#include <iostream>

bool path_find(std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& visited, int x, int y, int curr, const std::string& word) {
    if (curr == word.size()) {
        return true;
    }

    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visited[x][y] || board[x][y] != word[curr]) {
        return false;
    }

    visited[x][y] = true;

    bool found = path_find(board, visited, x - 1, y, curr + 1, word) ||  // up
                 path_find(board, visited, x + 1, y, curr + 1, word) ||  // down
                 path_find(board, visited, x, y - 1, curr + 1, word) ||  // left
                 path_find(board, visited, x, y + 1, curr + 1, word);    // right

    // If found is false, return it back
    if (not found) {
        visited[x][y] = false;
    }

    return found;
}

bool exist(std::vector<std::vector<char>>& board, const std::string& word) {
    int x_size = board.size();
    int y_size = board[0].size();

    std::vector<std::vector<bool>> visited(x_size, std::vector<bool>(y_size, false));

    for (int x = 0; x < x_size; ++x) {
        for (int y = 0; y < y_size; ++y) {
            if (board[x][y] == word[0] and path_find(board, visited, x, y, 0, word)) {
                return true;
            }
        }
    }

    return false;
}

auto main() -> int {
    auto board = std::vector<std::vector<char>>{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    std::cout << std::boolalpha << exist(board, "ABCCED") << std::endl;
    std::cout << std::boolalpha << exist(board, "SEE") << std::endl;
    std::cout << std::boolalpha << exist(board, "ABCB") << std::endl;
}
