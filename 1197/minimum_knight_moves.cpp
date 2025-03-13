#include <iostream>
#include <queue>
#include <utility>

int minKnightMoves(int x, int y) {
    // Implement BFS.
    // { order, { x, y } }

    std::queue<std::pair<int, std::pair<int, int>>> coords;
    coords.push(std::make_pair(0, std::make_pair(0, 0)));

    std::vector<std::pair<int, int>> directions = {
        {2, 1}, {2, -1}, {1, 2}, {1, -2}, 
        {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}
    };

    while (not coords.empty()) {
        // 1. Pop off queue, and check the coords
        auto curr = coords.front();
        int moves = curr.first;
        int curr_x = curr.second.first;
        int curr_y = curr.second.second;
        coords.pop();

        // std::cout << curr_x << ", " << curr_y << std::endl;

        if (curr_x == x and curr_y == y) return moves;

        for (const auto& direction : directions) {
            coords.push(std::make_pair(moves + 1, std::make_pair(curr_x + direction.first, curr_y + direction.second)));
        }
    }

    return 0;
}

int main() {
    std::cout << minKnightMoves(0, 0) << std::endl;     // 0
    std::cout << minKnightMoves(1, 2) << std::endl;     // 1
    std::cout << minKnightMoves(1, 1) << std::endl;     // 2
    std::cout << minKnightMoves(3, 3) << std::endl;     // 2
    std::cout << minKnightMoves(5, 5) << std::endl;     // 4
}
