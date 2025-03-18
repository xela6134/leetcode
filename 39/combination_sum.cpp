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

// void backtrack(int curr_index, int curr_sum, std::vector<int> curr_numbers, std::vector<int>& candidates, int& target, std::vector<std::vector<int>>& results) {
//     for (int i = curr_index; i < candidates.size(); ++i) {
//         // Add to curr_sum
//         int new_sum = curr_sum + candidates[i];

//         if (new_sum > target) {
//             return;
//         } else if (new_sum == target) {
//             curr_numbers.push_back(candidates[i]);
//             std::sort(curr_numbers.begin(), curr_numbers.end());
//             results.push_back(curr_numbers);
//             curr_numbers.pop_back();
//         } else {
//             curr_numbers.push_back(candidates[i]);
//             backtrack(i, new_sum, curr_numbers, candidates, target, results);
//             curr_numbers.pop_back();
//         }
//     }
// }

// auto combinationSum(std::vector<int>& candidates, int target) -> std::vector<std::vector<int>> {
//     std::vector<std::vector<int>> results;
//     // std::sort(candidates.begin(), candidates.end());
//     // curr_index, curr_sum, curr_numbers, candidates, target, results
//     // adding curr_sum as a parameter because using std::accumulate causes too much overload
//     backtrack(0, 0, {}, candidates, target, results);
//     return results;
// }

// {2, 3, 6, 7}, 7

// 2                     | 3     | 6 | 7
// 2 2           | 2 3   | 3 3
// 2 2 2 | 2 2 3 | 

void dfs(
    std::vector<int>& candidates, int target, int start, 
    std::vector<int>& currCombination, std::vector<std::vector<int>>& results
    ) {
    
    // Valid combination found if target == 0
    if (target == 0) {
        results.push_back(currCombination);
        return;
    }
    
    for (int i = start; i < candidates.size(); ++i) {
        // Cannot form a sum if the whole sum exceeds the target
        if (candidates[i] > target) {
            break;
        }
        
        // Choose the candidate and add it to the current combination
        currCombination.push_back(candidates[i]);

        // Recur with the updated target and same index (i) because we can reuse the same element
        dfs(candidates, target - candidates[i], i, currCombination, results);

        // Backtrack: remove the last element added before exploring the next candidate
        currCombination.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> results;
    std::vector<int> currCombination;
    std::sort(candidates.begin(), candidates.end());

    dfs(candidates, target, 0, currCombination, results);
    return results;
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
