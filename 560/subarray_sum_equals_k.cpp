#include <vector>
#include <numeric>
#include <iostream>
#include <unordered_map>

int subarraySum(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> prefix_sums;
    prefix_sums[0] = 1;  // Handles the case when a prefix sum itself equals k

    int count = 0;
    int curr_sum = 0;
    for (int num : nums) {
        curr_sum += num;
        if (prefix_sums.count(curr_sum - k)) {
            count += prefix_sums[curr_sum - k];
        }
        prefix_sums[curr_sum]++;
    }

    return count;
}

auto main() -> int {
    std::vector<int> nums;
    
    nums = {1,1,1};
    std::cout << subarraySum(nums, 2) << std::endl;

    nums = {1,2,3};
    std::cout << subarraySum(nums, 3) << std::endl;

    nums = {1,8,1,5,3,2,2,2,3,5,1};
    std::cout << subarraySum(nums, 9) << std::endl;

    //      0 1 2 3 4 5 6
    nums = {3,2,1,5,1,4,1};
    std::cout << subarraySum(nums, 6) << std::endl;
}
