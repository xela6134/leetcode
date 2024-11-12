#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

bool canPartition(std::vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) return false;
    sum = sum / 2;  // New sum

    // Now, from the current nums, make a DP like the 0/1 Knapsack Problem.
    std::sort(nums.begin(), nums.end());

    // e.g. if 2, 3, 5, 10 -> Check if we can make 10
    
    // We call this the (0/1 Knapsack Problem)

    // Capacity   →  0    1    2    3    4    5    6    7    8    9   10
    // Items ↓
    // 0 items       0    0    0    0    0    0    0    0    0    0    0
    // Item 1 (1, 2) 0    0    2    2    2    2    2    2    2    2    2
    // Item 2 (2, 3) 0    0    2    3    3    5    5    5    5    5    5
    // Item 3 (3, 5) 0    0    2    3    3    5    5    5    5    5   10 -> end
    // Item 4 (4,10) 0    

    // Capacity   →  0    1    2    3    4    5    6
    // Items ↓
    // 0 items       0    0    0    0    0    0    0
    // Item 1 (1, 2) 0    0    2    2    2    2    2
    // Item 2 (2, 2) 0    0    2    2    4    4    4
    // Item 3 (3, 3) 0    0    2    3    3
    // Item 4 (4, 5) 0    0    2    3    3

    std::vector<std::vector<int>> dp(nums.size() + 1, std::vector<int>(sum + 1, 0));

    // Loop 1:     Item loop
    // Loop 2: Capacity loop
    for (int i = 1; i <= nums.size(); ++i) {
        for (int j = 1; j <= sum; ++j) {
            // i) item number, j) capacity
            if (nums[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // Either include or exclude current item
                dp[i][j] = std::max(dp[i - 1][j], nums[i - 1] + dp[i - 1][j - nums[i - 1]]);
            }

            if (dp[i][j] == sum) {
                std::cout << i << ", " << j << std::endl;
                return true;
            }
        }
    }

    return false;
}

auto main() -> int {
    std::vector<int> nums;

    nums = {1, 5, 11, 5};
    std::cout << std::boolalpha << canPartition(nums) << std::endl;

    nums = {1, 2, 3, 5};
    std::cout << std::boolalpha << canPartition(nums) << std::endl;
    
    nums = {3, 9, 1, 7, 4};
    std::cout << std::boolalpha << canPartition(nums) << std::endl;

    nums = {1, 2, 5};
    std::cout << std::boolalpha << canPartition(nums) << std::endl;

    nums = {2, 2, 3, 5};
    std::cout << std::boolalpha << canPartition(nums) << std::endl;
}
