#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>

int rob(std::vector<int>& nums) {
    // 1: Either skip or rob house
    // 2: Maximum of skipping house or robbing house
    // 3: Values for index 0 and 1

    int n = nums.size();
    std::vector<int> dp(n, 0);

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            dp[0] = nums[0];
        } else if (i == 1) {
            dp[1] = std::max(nums[0], nums[1]);
        } else {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }
    }

    return dp[n - 1];
}

auto main() -> int {
    std::vector<int> nums1 = {1,2,3,1};
    std::cout << rob(nums1) << std::endl;

    std::vector<int> nums2 = {2,7,9,3,1};
    std::cout << rob(nums2) << std::endl;
}
