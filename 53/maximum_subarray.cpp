#include <vector>
#include <climits>
#include <iostream>

int maxSubArray(std::vector<int>& nums) {
    int max = INT_MIN;
    int curr = 0;

    for (int num : nums) {
        curr += num;
        max = std::max(max, curr);
        
        if (curr < 0) {
            curr = 0;
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
