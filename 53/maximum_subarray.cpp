#include <vector>
#include <limits>
#include <iostream>

auto maxSubArray(std::vector<int>& nums) -> int {
    int max = -2147483648;
    int sum = 0;

    for (int num : nums) {
        sum += num;
        max = std::max(max, sum);

        if (sum < 0) {
            sum = 0;
        }
    }

    return max;
}

auto main() -> int {
    std::vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    std::vector<int> nums2 = {5,4,-1,7,8};

    std::cout << maxSubArray(nums1) << std::endl;
    std::cout << maxSubArray(nums2) << std::endl;
}
