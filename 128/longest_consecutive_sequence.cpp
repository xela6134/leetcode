#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> found;
    for (int num : nums) {
        found.insert(num);
    }
    
    int longest = 0;
    for (int num : found) {
        // Start of list
        int length = 0;
        int curr = num;
        if (found.find(curr - 1) == found.end()) {
            // std::cout << "Dealing with " << curr << std::endl;

            while (found.find(curr) != found.end()) {
                ++curr;
                ++length;
            }
        }

        longest = std::max(longest, length);
    }

    return longest;
}

auto main() -> int {
    std::vector<int> nums1 = {100,4,200,1,3,2};
    std::cout << longestConsecutive(nums1) << std::endl;

    std::vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1};
    std::cout << longestConsecutive(nums2) << std::endl;

    std::vector<int> nums3 = {};
    std::cout << longestConsecutive(nums3) << std::endl;

    std::vector<int> nums4 = {1,2,0,1};
    std::cout << longestConsecutive(nums4) << std::endl;

    std::vector<int> nums5 = {0,0};
    std::cout << longestConsecutive(nums5) << std::endl;
}
