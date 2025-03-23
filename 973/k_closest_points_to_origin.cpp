#include <iostream>
#include <vector>
#include <queue>
#include <utility>

auto kClosest(std::vector<std::vector<int>> points, int k) -> std::vector<std::vector<int>> {
    std::priority_queue<std::pair<int, int>> maxHeap;

    for (int i = 0; i < points.size(); ++i) {
        maxHeap.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], i});
        if (maxHeap.size() > k) maxHeap.pop();
    }

    std::vector<std::vector<int>> result;
    while (!maxHeap.empty()) {
        result.push_back(points[maxHeap.top().second]);
        maxHeap.pop();
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
    print_result(kClosest({{1, 3}, {2, -2}}, 1));
    print_result(kClosest({{3, 3}, {5, -1}, {-2, 4}}, 2));
}
