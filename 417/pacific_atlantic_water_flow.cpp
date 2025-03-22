#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>>& heights, std::vector<std::vector<bool>>& flows, std::vector<std::vector<bool>>& visited, int horizontal_size, int vertical_size, int i, int j, bool& atlantic, bool& pacific) {
    // If already exists, no need to check
    if (flows[i][j]) {
        atlantic = true;
        pacific = true;
        return;
    }

    // For each of the directions, conduct a DFS. If out of bounds change either atlantic or pacific
    std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    for (auto direction : directions) {
        int x = i + direction.first;
        int y = j + direction.second;

        // Check out of bounds first, change atlantic & pacific
        if (x < 0 or y < 0) {
            pacific = true;
            if (pacific && atlantic) return;
        } else if (x >= vertical_size or y >= horizontal_size) {
            atlantic = true;
            if (pacific && atlantic) return;
        } else {
            // Only conduct DFS if neighbour_height <= current_height
            if (visited[x][y]) continue;
            
            visited[x][y] = true;
            if (heights[x][y] <= heights[i][j]) {
                dfs(heights, flows, visited, heights[0].size(), heights.size(), x, y, atlantic, pacific);
            }
        }
    }
}

auto pacificAtlantic(std::vector<std::vector<int>>& heights) -> std::vector<std::vector<int>> {
    std::vector<std::vector<bool>> flows(heights.size(), std::vector<bool>(heights[0].size(), false));

    std::vector<std::vector<int>> result;

    for (int i = 0; i < heights.size(); ++i) {
        for (int j = 0; j < heights[0].size(); ++j) {
            // Conduct a DFS
            bool atlantic = false, pacific = false;
            std::vector<std::vector<bool>> visited(heights.size(), std::vector<bool>(heights[0].size(), false));
            
            dfs(heights, flows, visited, heights[0].size(), heights.size(), i, j, atlantic, pacific);
            if (atlantic && pacific) {
                flows[i][j] = true;
                result.push_back({i, j});
            }
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
