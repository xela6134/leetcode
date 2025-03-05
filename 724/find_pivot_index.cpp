#include <vector>
#include <iostream>
#include <numeric>

int pivotIndex(std::vector<int>& nums) {
    // Loop through nums, keep track of left_sum = 0 & right_sum = std::accumulate()
    
    int left_sum = 0;
    int right_sum = std::accumulate(nums.begin(), nums.end(), 0) - nums[0];

    for (int i = 0; i < nums.size(); ++i) {
        // std::cout << i << ": " << left_sum << ", " << right_sum << std::endl;

        if (left_sum == right_sum) return i;

        left_sum += nums[i];
        
        if (i + 1 == nums.size()) break;
        right_sum -= nums[i + 1];
    }

    return -1;
}

int main() {
    std::vector<int> nums1 = {1,7,3,6,5,6};
    std::cout << pivotIndex(nums1) << std::endl;

    std::vector<int> nums2 = {1,2,3};
    std::cout << pivotIndex(nums2) << std::endl;

    std::vector<int> nums3 = {2,1,-1};
    std::cout << pivotIndex(nums3) << std::endl;

    std::vector<int> nums4 = {-1,-1,-1,-1,-1,0};
    std::cout << pivotIndex(nums4) << std::endl;
}
