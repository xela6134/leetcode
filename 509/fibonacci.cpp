#include <iostream>
#include <vector>

int fib(int n) {
    if (n == 0) return 0;

    // Space-complexity wise shit but time-complexity wise great
    std::vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {

}
