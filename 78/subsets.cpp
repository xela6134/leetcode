#include <vector>
#include <algorithm>
#include <iostream>

void backtrack(std::vector<std::vector<int>>& result, int index, std::vector<int>& curr, std::vector<int>& nums) {
    result.push_back(curr);

    for (int i = index; i < nums.size(); ++i) {
        curr.push_back(nums[i]);
        backtrack(result, i + 1, curr, nums);
        curr.pop_back();
    }
}

auto subsets(std::vector<int>& nums) -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> result;
    std::vector<int> curr;
    backtrack(result, 0, curr, nums);
    
    return result;
}

auto print_result(std::vector<std::vector<int>>& result) {
    for (std::vector<int> vec : result) {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

auto main() -> int {
    std::vector<int> nums = {1,2,3};
    std::vector<std::vector<int>> result = subsets(nums);

    print_result(result);
}
