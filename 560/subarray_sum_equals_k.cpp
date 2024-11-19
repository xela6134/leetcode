#include <vector>
#include <numeric>
#include <iostream>

// Works if everything is positive
int subarraySum_initial(std::vector<int>& nums, int k) {
    // k = 6
    // 3, 2, 1, 5, 1, 4, 1
    int count = 0;
    int left = 0, right = 0;
    int curr_sum = nums[0];

    while (left != nums.size() and right != nums.size()) {
        std::cout << "For left = " << left << " and right = " << right << ", curr_sum is " << curr_sum << std::endl;

        // Check if current value = k
        if (curr_sum == k) ++count;

        // Case 0: right = nums.size() - 1
        // ++left, curr_sum -= nums[left]
        if (right == nums.size() - 1) {
            curr_sum -= nums[left];
            ++left;
        }

        // Case 1: curr_sum < k
        // ++right, curr_sum += nums[right]
        else if (curr_sum < k) {
            ++right;
            curr_sum += nums[right];
        }

        // Case 2: curr_sum = k
        // ++left, ++right, curr_sum += nums[right], curr_sum -= nums[left]
        else if (curr_sum == k) {
            ++right;
            curr_sum += nums[right];
            curr_sum -= nums[left];
            ++left;
        }

        // Case 3: curr_sum > k
        // ++left, curr_sum -= nums[left]
        else {
            curr_sum -= nums[left];
            ++left;
        }
    }

    return count;
}

// Answer
int subarraySum(std::vector<int>& nums, int k) {
    
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
