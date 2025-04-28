#include <iostream>
#include <vector>
#include <unordered_set>

// 1 2 3 4

//  1           2           3           4
//  1 2 1 3 1 4 2 3 2 4     3 4

void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& curr, int start, int n, int k) {
    if (curr.size() == k) {
        result.push_back(curr);
        return;
    }

    for (int i = start; i <= n; ++i) {
        curr.push_back(i);
        backtrack(result, curr, i + 1, n, k);
        curr.pop_back();
    }
}

std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> result;
    std::vector<int> curr;
    backtrack(result, curr, 1, n, k);
    return result;
}

void print_result(std::vector<std::vector<int>>& result) {
    for (const auto& vec : result) {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    auto result = combine(4, 2);
    print_result(result);

    result = combine(1, 1);
    print_result(result);
}
