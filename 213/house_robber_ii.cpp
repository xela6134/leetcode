#include <iostream>
#include <vector>
#include <algorithm>

int rob_specific(const std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    std::vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);
    
    for (int i = 2; i < n; ++i) {
        dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
    }
    
    return dp[n-1];
}

int rob(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    
    // Exclude first house
    std::vector<int> excludeFirst(nums.begin() + 1, nums.end());

    // Exclude last house
    std::vector<int> excludeLast(nums.begin(), nums.end() - 1);
    
    return std::max(rob_specific(excludeFirst), rob_specific(excludeLast));
}

int main() {

}
