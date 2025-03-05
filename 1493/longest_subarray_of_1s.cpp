#include <iostream>
#include <vector>
#include <algorithm>

int longestSubarray(std::vector<int>& nums) {
    // Sliding window, but window size can change all the time
    // If next element is 1, ++right
    // If next element is 0 and zeroes_used is <= k, ++right, ++zeroes_used
    // Else, ++left. If zero encountered, --zeroes_used
    // Terminate when right >= nums.size()    
    int left = 0;
    int right = 0;
    int zeroes_used = 0;
    int max_size = 0;

    while (right < nums.size()) {
        if (nums[right] == 0) ++zeroes_used;

        while (zeroes_used > 1) {
            if (nums[left] == 0) --zeroes_used;
            ++left;
        }

        max_size = std::max(max_size, right - left);
        ++right;
    }

    return max_size;
}

int main() {
    // std::vector<int> nums1 = {1,1,0,1};
    // std::cout << longestSubarray(nums1) << std::endl;

    // std::vector<int> nums2 = {0,1,1,1,0,1,1,0,1};
    // std::cout << longestSubarray(nums2) << std::endl;

    std::vector<int> nums3 = {1,0,1,1,1,1,1,1,0,1,1,1,1,1};
    std::cout << longestSubarray(nums3) << std::endl;
}
