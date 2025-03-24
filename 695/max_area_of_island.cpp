#include <iostream>
#include <vector>
#include <algorithm>

// void dfs(std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& visited, int i, int j, int& curr_area, int horizontal, int vertical) {
//     std::vector<std::pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

//     visited[i][j] = true;
//     ++curr_area;

//     for (const auto& direction : directions) {
//         int x = i + direction.first;
//         int y = j + direction.second;

//         // For the DFS to be valid - 
//         // 0. x and y should be within bounaries
//         // 1. Next grid must be 1
//         // 2. Next grid must not be visited

//         if (x >= 0 and x < vertical and y >= 0 and y < horizontal and grid[x][y] == 1 and visited[x][y] == false) {
//             dfs(grid, visited, x, y, curr_area, horizontal, vertical);
//         }
//     }
    
//     return;
// }

// int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
//     std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
//     int max_area = 0;

//     for (int i = 0; i < grid.size(); ++i) {
//         for (int j = 0; j < grid[0].size(); ++j) {
//             if (not visited[i][j] and grid[i][j] == 1) {
//                 int curr_area = 0;
//                 dfs(grid, visited, i, j, curr_area, grid[0].size(), grid.size());
//                 max_area = std::max(max_area, curr_area);
//             }
//         }
//     }

//     return max_area;
// }

int dfs(std::vector<std::vector<int>>& grid, int i, int j) {
    // Check boundaries and whether the cell is water (or already visited)
    if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or grid[i][j] == 0) return 0;
    
    // Mark current cell as visited by setting it to 0
    grid[i][j] = 0;
    
    // Recursively visit all four directions and add their area
    return 1 + dfs(grid, i - 1, j) 
             + dfs(grid, i + 1, j) 
             + dfs(grid, i, j - 1) 
             + dfs(grid, i, j + 1);
}

int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
    int max_area = 0;
    
    // Loop over every cell in the grid
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            // If the cell is land, calculate the island's area
            if (grid[i][j] == 1) {
                int curr_area = dfs(grid, i, j);
                max_area = std::max(max_area, curr_area);
                
                // std::cout << "Island starting at (" << i << ", " << j << ") has area: " << curr_area << std::endl;
            }
        }
    }
    
    return max_area;
}

int main() {
    std::vector<std::vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };

    std::cout << maxAreaOfIsland(grid) << std::endl;
}
