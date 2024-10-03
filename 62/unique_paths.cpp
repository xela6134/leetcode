#include <vector>
#include <iostream>
#include <algorithm>

int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 1));

    if (m == 1 or n == 1) {
        return 1;
    }

    if (m == 2 or n == 2) {
        return std::max(m, n);
    }

    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 1; j < matrix[0].size(); ++j) {
            matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
        }
    }

    return matrix[m - 1][n - 1];
}

auto main() -> int {
    std::cout << uniquePaths(3, 7) << std::endl;
    std::cout << uniquePaths(2, 3) << std::endl;
}
