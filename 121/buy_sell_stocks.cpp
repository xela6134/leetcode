#include <vector>
#include <iostream>
#include <climits>

// 7, 1, 5, 3, 6, 4
int maxProfit(std::vector<int>& prices) {
    int min = INT_MAX;
    int max_profit = 0;

    for (int i = 0; i < prices.size(); ++i) {
        if (i != 0 and prices[i] - min > max_profit) {
            max_profit = prices[i] - min;
        }

        if (prices[i] < min) {
            min = prices[i];
        }
    }

    return max_profit;
}

auto main() -> int {
    std::vector<int> prices1 = {7,1,5,3,6,4};
    std::cout << maxProfit(prices1) << std::endl;

    std::vector<int> prices2 = {7,6,4,3,1};
    std::cout << maxProfit(prices2) << std::endl;
}
