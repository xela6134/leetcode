#include <iostream>
#include <vector>
#include <algorithm>

int minCostClimbingStairs(std::vector<int>& cost) {
    int size = cost.size();
    if (size == 2) return std::min(cost[0], cost[1]);

    // 0,0   2,5,5,9  ,10,11,12 ,12
    // 2,100,3,4,5,100,1 ,1 ,100,1

    // dp[2] = 2
    // dp[3] = 2 + 3
    // dp[4] = 
    // dp[5] = 
    // dp[6] = 

    std::vector<int> dp(size + 1, 0);
    dp[0] = 0, dp[1] = 0;

    for (int i = 2; i < size + 1; ++i) {
        if (cost[i-2] + dp[i-2] > cost[i-1] + dp[i-1]) {
            dp[i] = cost[i-1] + dp[i-1];
        } else {
            dp[i] = cost[i-2] + dp[i-2];
        }
    }

    return dp[size];
}

int main() {
    std::vector<int> cost1 = {10,15,20};
    std::vector<int> cost2 = {1,100,1,1,1,100,1,1,100,1};
    std::cout << minCostClimbingStairs(cost1) << std::endl;
    std::cout << minCostClimbingStairs(cost2) << std::endl;
}
