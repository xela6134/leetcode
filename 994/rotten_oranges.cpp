#include <vector>
#include <queue>
#include <utility>
#include <iostream>

int orangesRotting(std::vector<std::vector<int>>& grid) {
    // 1. Start graph traversals from 2's

    // 2. Conduct BFS. BFS should be structure of {{x, y}, minute}

    // 3. Check for any 1's after graph traversal finished.
    // - 1 X: return 'max minute'
    // - 1 O: return -1

    std::queue<std::pair<std::pair<int, int>, int>> queue;

    for (int x = 0; x < grid.size(); ++x) {
        for (int y = 0; y < grid[0].size(); ++y) {
            if (grid[x][y] == 2) {
                queue.push({{x, y}, 0});
            }
        }
    }

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int max_minute = 0;

    while (not queue.empty()) {
        auto [coords, minute] = queue.front();
        auto [x, y] = coords;
        queue.pop();

        for (const auto& d : directions) {
            int new_x = x + d[0];
            int new_y = y + d[1];

            if (new_x >= 0 and new_y >= 0 and new_x < grid.size() and new_y < grid[0].size() and grid[new_x][new_y] == 1) {
                grid[new_x][new_y] = 2;
                int new_minute = minute + 1;
                
                queue.push({{new_x, new_y}, new_minute});
                if (max_minute < new_minute) max_minute = new_minute;
            }
        }
    }

    for (int x = 0; x < grid.size(); ++x) {
        for (int y = 0; y < grid[0].size(); ++y) {
            if (grid[x][y] == 1) {
                return -1;
            }
        }
    }

    return max_minute;
}

auto main() -> int {
    std::vector<std::vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    std::cout << orangesRotting(grid) << std::endl;

    grid = {{2,1,1},{0,1,1},{1,0,1}};
    std::cout << orangesRotting(grid) << std::endl;

    grid = {{0, 2}};
    std::cout << orangesRotting(grid) << std::endl;
}
