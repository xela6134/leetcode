#include <iostream>
#include <vector>

int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    std::vector<int> dp(n, 0);
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n-1];
}

auto main() -> int {
    std::cout << climbStairs(3) << std::endl;
    std::cout << climbStairs(4) << std::endl;
    std::cout << climbStairs(5) << std::endl;
}