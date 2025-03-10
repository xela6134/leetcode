#include <iostream>
#include <vector>
#include <algorithm>

int longestOnes(std::vector<int>& nums, int k) {
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

        while (zeroes_used > k) {
            if (nums[left] == 0) --zeroes_used;
            ++left;
        }

        max_size = std::max(max_size, right - left + 1);
        ++right;
    }

    return max_size;
}

int main() {
    std::vector<int> nums1 = {1,1,1,0,0,0,1,1,1,1,0};
    std::cout << longestOnes(nums1, 2) << std::endl;

    std::vector<int> nums2 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    std::cout << longestOnes(nums2, 3) << std::endl;
}
