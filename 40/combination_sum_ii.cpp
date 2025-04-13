#include <iostream>
#include <vector>
#include <algorithm>

// 10,1,2,7,6,1,5
// 1 1 2 5 6 7 10

void backtrack(std::vector<int>& candidates, std::vector<std::vector<int>>& result, std::vector<int> curr_vector, int start, int curr_sum, int target) {
    if (curr_sum == target) {
        result.push_back(curr_vector);
        return;
    }

    for (int i = start; i < candidates.size(); ++i) {
        if (candidates[i] + curr_sum > target) break;
        
        // Stops duplicate element being added 'on the same level'.
        if (i > start && candidates[i] == candidates[i - 1]) continue;

        curr_vector.push_back(candidates[i]);
        backtrack(candidates, result, curr_vector, i + 1, curr_sum + candidates[i], target);
        curr_vector.pop_back();
    }
}

auto combinationSum2(std::vector<int> candidates, int target) -> std::vector<std::vector<int>> {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> result;
    backtrack(candidates, result, {}, 0, 0, target);
    return result;
}

void print_result(std::vector<std::vector<int>> result) {
    for (const auto& vec : result) {
        for (int num : vec) {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }
}

int main() {
    auto result1 = combinationSum2({10,1,2,7,6,1,5}, 8);
    auto result2 = combinationSum2({2,5,2,1,2}, 5);
    print_result(result1);
    std::cout << std::endl;
    print_result(result2);
}
