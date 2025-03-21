#include <vector>
#include <iostream>
#include <climits>

// 7, 1, 5, 3, 6, 4
// Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

// 7, 6, 4, 3, 1
// In this case, no transactions are done and the max profit = 0
int maxProfit(std::vector<int>& prices) {
    int max_profit = 0;
    int min_price = prices[0];

    for (int i = 1; i < prices.size(); ++i) {
        max_profit = std::max(max_profit, prices[i] - min_price);
        min_price = std::min(min_price, prices[1]);
    }

    return max_profit;
}

auto main() -> int {
    std::vector<int> prices1 = {7,1,5,3,6,4};
    std::cout << maxProfit(prices1) << std::endl;

    std::vector<int> prices2 = {7,6,4,3,1};
    std::cout << maxProfit(prices2) << std::endl;
}
