#include <vector>
#include <iostream>
#include <algorithm>

int maxProduct(std::vector<int>& nums) {
    int curr_min = nums[0];
    int curr_max = nums[0];
    int whole_max = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        // Swapping is necessary when current num is negative
        if (nums[i] < 0) {
            std::swap(curr_max, curr_min);
        }

        curr_min = std::min(nums[i], curr_min * nums[i]);
        curr_max = std::max(nums[i], curr_max * nums[i]);        
        whole_max = std::max(curr_max, whole_max);
    }

    return whole_max;
}

auto main() -> int {
    std::vector<int> nums = {-1,4,-4,5};
    std::cout << maxProduct(nums) << std::endl;
}
