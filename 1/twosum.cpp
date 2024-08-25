#include <vector>
#include <iostream>
#include <unordered_map>
#include <utility>

auto twoSum(std::vector<int>& nums, int target) -> std::vector<int> {
    auto num_map = std::unordered_map<int, int>{};

    for (int i = 0; i < nums.size(); ++i) {
        if (num_map.contains(target - nums[i])) {
            return {num_map[target - nums[i]], i};
        }
        num_map[nums[i]] = i;
    }

    return {};
}

auto main() -> int {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto result = twoSum(nums, target);
    std::cout << result[0] << ", " << result[1] << std::endl;
    return 0;
}
