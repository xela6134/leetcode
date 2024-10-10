#include <vector>
#include <iostream>

auto print_result(std::vector<std::vector<int>>& result) {
    for (std::vector<int> line : result) {
        for (int num : line) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

void make_tree(std::vector<std::vector<int>>& result, std::vector<int>& curr, int depth, int numRows) {
    result.push_back(curr);
    if (depth >= numRows) return;

    std::vector<int> next;

    ++depth;
    for (int i = 0; i < depth; ++i) {
        if (i == 0) {
            next.push_back(1);
        } else if (i == depth - 1) {
            next.push_back(1);
        } else {
            next.push_back(curr[i - 1] + curr[i]);
        }
    }
    make_tree(result, next, depth, numRows);
}

auto generate(int numRows) -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> result;
    std::vector<int> curr = {1};
    make_tree(result, curr, 1, numRows);
    return result;
}

auto main() -> int {
    std::vector<std::vector<int>> result = generate(5);
    print_result(result);
}