#include <vector>
#include <queue>
#include <utility>
#include <iostream>

void bfs(int i, int j, std::vector<std::vector<char>>& grid) {
    std::queue<std::pair<int, int>> q;
    q.push({i, j});
    
    grid[i][j] = '0';
    
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // Explore top, bottom, left, right
        for (auto& d : directions) {
            int newX = x + d[0];
            int newY = y + d[1];
            
            if (newX >= 0 && newX < grid.size() and newY >= 0 && newY < grid[0].size() and grid[newX][newY] == '1') {
                grid[newX][newY] = '0';  // Mark as visited
                q.push({newX, newY});
            }
        }
    }
}

int numIslands(std::vector<std::vector<char>>& grid) {
    int islands = 0;
    
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == '1') {
                bfs(i, j, grid);
                ++islands;
            }
        }
    }

    return islands;
}

auto main() -> int {
    std::vector<std::vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    std::cout << numIslands(grid1) << std::endl;

    std::vector<std::vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    
    std::cout << numIslands(grid2) << std::endl;
}