#include <iostream>
#include <vector>

int deleteAndEarn(std::vector<int>& nums) {
    int max_element = *std::max_element(nums.begin(), nums.end());

    std::vector<int> points(max_element + 1, 0);

    for (int num : nums) {
        points[num] += num;
    }

    // P.S. In {2,2,3,3,3,4}, picking '3' means you can pick all 3 instances of 3
    // Not much different to the House Robber problem

    // DP
    // Definition: dp[i] = max points you can earn when you pick
    // Base Case : dp[0] = 0, dp[1] = max(points[0], points[1]) [ no dp[i-2] to pick ]
    // Recurrence: dp[i] = max(dp[i-1], dp[i-2] + points[i])

    std::vector<int> dp(max_element + 1, 0);
    for (int i = 0; i <= max_element; ++i) {
        if (i == 0) {
            dp[i] = points[0];
        } else if (i == 1) {
            dp[i] = std::max(points[0], points[1]);
        } else {
            dp[i] = std::max(dp[i-1], dp[i-2] + points[i]);
        }
    }

    return std::max(dp[max_element], dp[max_element-1]);
}

int main() {
    
}
