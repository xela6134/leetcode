#include <vector>
#include <iostream>

auto spiralOrder(std::vector<std::vector<int>>& matrix) -> std::vector<int> {
    auto result = std::vector<int>{};

    int left = 0;
    int right = matrix[0].size() - 1;
    int top = 0;
    int bottom = matrix.size() - 1;

    int i = 0;
    int j = 0;
    int direction = 0;
    // 0: right
    // 1: down
    // 2: left
    // 3: top

    while (left <= right and top <= bottom) {
        result.push_back(matrix[i][j]);

        if (direction == 0) {
            if (j == right) {
                ++i;
                direction = 1;
                ++top;
            } else {
                ++j;
            }
        } else if (direction == 1) {
            if (i == bottom) {
                --j;
                direction = 2;
                --right;
            } else {
                ++i;
            }
        } else if (direction == 2) {
            if (j == left) {
                --i;
                direction = 3;
                --bottom;
            } else {
                --j;
            }
        } else {
            if (i == top) {
                ++j;
                direction = 0;
                ++left;
            } else {
                --i;
            }
        }
    }

    return result;
}

auto main() -> int {
    std::vector<int> row1 = {1,2,3,4};
    std::vector<int> row2 = {5,6,7,8};
    std::vector<int> row3 = {9,10,11,12};
    std::vector<std::vector<int>> matrix = {};
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    
    std::vector<int> order = spiralOrder(matrix);
    for (int num : order) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
