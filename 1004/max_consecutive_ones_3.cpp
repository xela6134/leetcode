#include <iostream>
#include <vector>
#include <algorithm>

int longestOnes(std::vector<int>& nums, int k) {
    // Sliding window, but window size can change all the time
    // Keep expanding right if next element is 1
    // Can keep expanding if next element is 0, when 'zeroes_used' is <= k
    // If 'zeroes_used' > k, move right AND left.
    // In each iteration, count the maximum window size.

    int left = 0;
    int right = 0;
    int zeroes_used = 0;
    int max_window_size = 0;

    while (right < nums.size()) {
        if (nums[right] == 1) {
            ++right;
        }

        else if (nums[right] == 0 and zeroes_used < k) {
            ++right;
            ++zeroes_used;
        }

        else {
            if (nums[left] == 0) --zeroes_used;
            ++left;
        }

        max_window_size = std::max(max_window_size, right - left);
    }

    return max_window_size;
}

int main() {
    std::vector<int> nums1 = {1,1,1,0,0,0,1,1,1,1,0};
    std::cout << longestOnes(nums1, 2) << std::endl;

    std::vector<int> nums2 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    std::cout << longestOnes(nums2, 3) << std::endl;
}
