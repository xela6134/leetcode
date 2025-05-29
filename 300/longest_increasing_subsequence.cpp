#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

int lengthOfLIS(std::vector<int>& nums) {
    std::vector<int> tails;

    // 10 -> [10]
    // 9 -> [9]
    // 2 -> [2]
    // 5 -> [2, 5]
    // 3 -> [2, 3]
    // 7 -> [2, 3, 7]
    // 101 -> [2, 3, 7, 101]
    // 18 -> [2, 3, 7, 18]

    for (int num : nums) {
        // Binary search for the first element >= num
        auto it = std::lower_bound(tails.begin(), tails.end(), num);

        if (it == tails.end()) {
            tails.push_back(num); // Extend the sequence
        } else {
            *it = num; // Replace to maintain the smallest tail
        }
    }

    return tails.size();
}

auto main() -> int {
    std::vector<int> nums;

    nums = {10,9,2,5,3,7,101,18};
    std::cout << lengthOfLIS(nums) << std::endl;

    nums = {0,1,0,3,2,3};
    std::cout << lengthOfLIS(nums) << std::endl;

    nums = {7,7,7,7,7,7,7};
    std::cout << lengthOfLIS(nums) << std::endl;
}
