#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

int lengthOfLIS(std::vector<int>& nums) {
    // 10 9 2 5 3 7 101 18
    // 1  1 1 2 2 3 4   4
    int n = nums.size();
    std::vector<int> dp(n);

    int max_length = 1;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            dp[i] = 1;
            continue;
        }

        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        max_length = std::max(max_length, dp[i]);
    }

    return max_length;
}

auto main() -> int {
    std::vector<int> nums;

    nums = {10,9,2,5,3,7,101,18};
    std::cout << lengthOfLIS(nums) << std::endl;

    nums = {0,1,0,3,2,3};
    std::cout << lengthOfLIS(nums) << std::endl;

    nums = {7,7,7,7,7,7,7};
    std::cout << lengthOfLIS(nums) << std::endl;
}
