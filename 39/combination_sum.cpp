#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

auto find_combinations(int start, int sum, int target, std::vector<int>& candidates, std::vector<int>& current, std::vector<std::vector<int>>& result) {
    if (sum == target) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < candidates.size(); ++i) {
        if (candidates[i] + sum > target) break;

        current.push_back(candidates[i]);
        find_combinations(i, sum + candidates[i], target, candidates, current, result);
        current.pop_back();
    }
}

auto combinationSum(std::vector<int>& candidates, int target) -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> result;
    std::vector<int> current;

    std::sort(candidates.begin(), candidates.end());

    find_combinations(0, 0, target, candidates, current, result);

    return result;
}

auto main() -> int {
    std::vector<int> candidates = {2, 3, 6, 7};
    std::vector<std::vector<int>> combinations = combinationSum(candidates, 7);

    for (std::vector<int> combination : combinations) {
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}
