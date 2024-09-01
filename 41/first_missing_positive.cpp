#include <vector>
#include <iostream>
#include <algorithm>

auto firstMissingPositive(std::vector<int>& nums) -> int {
    int n = nums.size();
    
    for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 and nums[i] <= n and nums[nums[i] - 1] != nums[i]) {
            std::swap(nums[i], nums[nums[i] - 1]);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    
    return n + 1;
}

auto main() -> int {
    std::vector<int> nums = {7,8,9,11,12};
    std::cout << firstMissingPositive(nums) << std::endl;
    
    nums = {1, 2, 0};
    std::cout << firstMissingPositive(nums) << std::endl;
    
    nums = {3, 4, -1, 1};
    std::cout << firstMissingPositive(nums) << std::endl;
}
