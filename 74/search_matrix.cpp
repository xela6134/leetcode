#include <vector>
#include <iostream>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int horizontal = matrix[0].size();
    int vertical = matrix.size();
    
    int left = 0;
    int right = horizontal * vertical - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int m = mid / horizontal;
        int n = mid % horizontal;

        int val = matrix[m][n];

        // std::cout << "left: " << left << ", right: " << right << ", mid: " << mid << " m: " << m << ", n: " << n << ", val: " << val << std::endl;

        if (val == target) {
            return true;
        } else if (val < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

auto main() -> int {
    std::vector<std::vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };

    std::cout << std::boolalpha << searchMatrix(matrix, 3) << std::endl;
    std::cout << std::boolalpha << searchMatrix(matrix, 13) << std::endl;
}
