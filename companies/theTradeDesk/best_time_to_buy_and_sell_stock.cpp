#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int max_profit = 0;
        int lowest_price = prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            lowest_price = std::min(lowest_price, prices[i]);
            max_profit = std::max(max_profit, prices[i] - lowest_price);
        }

        return max_profit;
    }
};