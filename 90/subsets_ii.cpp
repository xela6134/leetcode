#include <iostream>
#include <vector>

void backtrack(std::vector<std::vector<int>>& results, std::vector<int>& nums, std::vector<int> result, int start) {
    results.push_back(result);

    for (int i = start; i < nums.size(); ++i) {
        if (i > start and nums[i] == nums[i-1]) continue;

        if (result.size() < nums.size()) {
            result.push_back(nums[i]);
            backtrack(results, nums, result, i + 1);
            result.pop_back();
        }
    }
}

std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> results;
    backtrack(results, nums, {}, 0);
    return results;
}

int main() {

}
