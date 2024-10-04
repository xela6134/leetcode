#include <vector>
#include <iostream>
#include <algorithm>

int minPathSum(std::vector<std::vector<int>>& grid) {
    int cols = grid[0].size();
    int rows = grid.size(); 

    std::vector<std::vector<int>> sum(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 and j == 0) {
                sum[i][j] = grid[i][j];
            } else if (i == 0) {
                sum[i][j] = grid[i][j] + sum[i][j - 1];
            } else if (j == 0) {
                sum[i][j] = grid[i][j] + sum[i - 1][j];
            } else {
                sum[i][j] = grid[i][j] + std::min(sum[i][j - 1], sum[i - 1][j]);
            }
        }
    }

    return sum[rows - 1][cols - 1];
}

auto main() -> int {
    std::vector<std::vector<int>> grid1 = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    std::cout << minPathSum(grid1) << std::endl;

    std::vector<std::vector<int>> grid2 = {
        {1,2,3},
        {4,5,6}
    };

    std::cout << minPathSum(grid2) << std::endl;
}
