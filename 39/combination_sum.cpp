#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

// auto find_combinations(int start, int sum, int target, std::vector<int>& candidates, std::vector<int>& current, std::vector<std::vector<int>>& result) {
//     if (sum == target) {
//         result.push_back(current);
//         return;
//     }

//     for (int i = start; i < candidates.size(); ++i) {
//         if (candidates[i] + sum > target) break;

//         current.push_back(candidates[i]);
//         find_combinations(i, sum + candidates[i], target, candidates, current, result);
//         current.pop_back();
//     }
// }

// auto combinationSum(std::vector<int>& candidates, int target) -> std::vector<std::vector<int>> {
//     std::vector<std::vector<int>> result;
//     std::vector<int> current;

//     std::sort(candidates.begin(), candidates.end());

//     find_combinations(0, 0, target, candidates, current, result);

//     return result;
// }

void backtrack(int index, int curr_sum, std::vector<int> curr_nums, int target, std::vector<std::vector<int>>& result, std::vector<int>& candidates) {
    for (int i = index; i < candidates.size(); ++i) {
        int candidate = candidates[i];
        int new_sum = curr_sum + candidate;

        std::vector<int> new_nums = curr_nums;
        new_nums.push_back(candidate);

        if (new_sum > target) {
            return;
        } else if (new_sum == target) {
            std::sort(new_nums.begin(), new_nums.end());
            result.push_back(new_nums);
            return;
        } else {
            backtrack(i, new_sum, new_nums, target, result, candidates);
        }
    }
}

auto combinationSum(std::vector<int>& candidates, int target) -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> result;
    std::sort(candidates.begin(), candidates.end());

    // Variables Needed: index, current_sum, target, result, candidates
    backtrack(0, 0, {}, target, result, candidates);

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
