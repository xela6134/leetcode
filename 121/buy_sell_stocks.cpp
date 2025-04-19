#include <vector>
#include <iostream>
#include <climits>

int maxProfit(std::vector<int>& prices) {
    int minimum = prices[0];
    int max_profit = 0;

    for (int i = 1; i < prices.size(); ++i) {
        minimum = std::min(minimum, prices[i]);
        max_profit = std::max(max_profit, prices[i] - minimum);
    }

    return max_profit;
}

auto main() -> int {
    std::vector<int> prices1 = {7,1,5,3,6,4};
    std::cout << maxProfit(prices1) << std::endl;

    std::vector<int> prices2 = {7,6,4,3,1};
    std::cout << maxProfit(prices2) << std::endl;
}
