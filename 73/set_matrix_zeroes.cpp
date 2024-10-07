#include <vector>
#include <iostream>
#include <unordered_map>
#include <utility>

void change_zeroes(std::vector<std::vector<int>>& matrix, int i, int j) {
    // horizontal
    for (int n = 0; n < matrix[0].size(); ++n) {
        matrix[i][n] = 0;
    }

    // vertical
    for (int n = 0; n < matrix.size(); ++n) {
        matrix[n][j] = 0;
    }
}

void setZeroes(std::vector<std::vector<int>>& matrix) {
    std::vector<std::pair<int, int>> coordinates;

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[i][j] == 0) {
                coordinates.push_back(std::make_pair(i, j));
            }
        }
    }

    for (std::pair<int, int> coordinate : coordinates) {
        change_zeroes(matrix, coordinate.first, coordinate.second);
    }
}

auto print_matrix(std::vector<std::vector<int>>& matrix) {
    for (std::vector<int> line : matrix) {
        for (int num : line) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

auto main() -> int {
    std::vector<std::vector<int>> matrix1 = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    setZeroes(matrix1);
    print_matrix(matrix1);
    std::cout << std::endl;

    std::vector<std::vector<int>> matrix2 = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    setZeroes(matrix2);
    print_matrix(matrix2);
}
