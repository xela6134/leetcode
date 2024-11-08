#include <vector>
#include <algorithm>
#include <iostream>

void print_vector(std::vector<int>& nums) {
    for (int& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1);

    for (int& coin : coins) {
        if (coin > amount) continue;
        dp[coin] = 1;
    }

    for (int i = 1; i <= amount; ++i) {
        dp[i] = -1;

        // If i is 2, and coin is {3, 5}
        for (int& coin : coins) {
            if (i - coin < 0 or dp[i - coin] == -1) continue;
            
            if (dp[i] < 1) {
                dp[i] = dp[i - coin] + 1;
            } else {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    print_vector(dp);

    return dp[amount];
}

auto main() -> int {
    std::vector<int> coins;
    
    coins = {1, 2, 5};
    std::cout << coinChange(coins, 11) << std::endl;

    coins = {2, 5};
    std::cout << coinChange(coins, 7) << std::endl;

    coins = {2};
    std::cout << coinChange(coins, 3) << std::endl;
}
