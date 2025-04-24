#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int missingNumber(std::vector<int>& nums) {
    int max = *std::max_element(nums.begin(), nums.end());
    int sum = std::accumulate(nums.begin(), nums.end(), 1);

    int total = max * (max + 1) / 2;
    return total - sum;
}

int main() {

}
