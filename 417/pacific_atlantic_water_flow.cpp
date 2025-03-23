#include <iostream>
#include <vector>
#include <utility>

void dfs(std::vector<std::vector<int>>& heights, int i, int j, std::vector<std::vector<bool>>& reachable) {
    int m = heights.size(), n = heights[0].size();
    reachable[i][j] = true;
    std::vector<std::pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    for (auto dir : directions) {
        int x = i + dir.first, y = j + dir.second;

        // Check bounds and if the cell is already visited
        if (x < 0 or x >= m or y < 0 or y >= n or reachable[x][y]) continue;

        // Only move if neighbour's height is not less than current cell's height
        if (heights[x][y] < heights[i][j]) continue;

        dfs(heights, x, y, reachable);
    }
}

std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
    if (heights.empty())
        return {};
    int m = heights.size(), n = heights[0].size();

    std::vector<std::vector<bool>> pacific(m, std::vector<bool>(n, false));
    std::vector<std::vector<bool>> atlantic(m, std::vector<bool>(n, false));
    
    // DFS from borders
    for (int i = 0; i < m; ++i) {
        dfs(heights, i, 0, pacific);        // Left column
        dfs(heights, i, n-1, atlantic);     // Right column
    }

    for (int j = 0; j < n; ++j) {
        dfs(heights, 0, j, pacific);        // Top row
        dfs(heights, m-1, j, atlantic);     // Bottom row
    }
    
    // Collect cells that can reach both oceans
    std::vector<std::vector<int>> result;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (pacific[i][j] && atlantic[i][j])
                result.push_back({i, j});
        }
    }
    return result;
}

void print_result(std::vector<std::vector<int>> result) {
    for (auto vec : result) {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> heights = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };

    print_result(pacificAtlantic(heights));
}
