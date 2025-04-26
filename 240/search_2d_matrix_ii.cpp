#include <iostream>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int row = matrix.size() - 1;
    int col = 0;

    while (row >= 0 and col < matrix[0].size()) {
        if (matrix[row][col] > target) row--;
        else if (matrix[row][col] < target) col++;
        else return true;
    }

    return false;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30},
    };

    bool result = searchMatrix(matrix, 5);
    std::cout << std::boolalpha << std::endl << result << std::endl;

    result = searchMatrix(matrix, 20);
    std::cout << std::boolalpha << std::endl << result << std::endl;
}
