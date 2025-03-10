#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> numbers;

    for (int num : nums) {
        numbers.insert(num);
    }

    int max = 0;

    for (int num : numbers) {
        if (numbers.find(num - 1) == numbers.end()) {
            // We have a place to start, keep looping
            int size = 1;
            int curr = num;

            while (numbers.find(curr + 1) != numbers.end()) {
                ++size;
                ++curr;
            }

            max = std::max(size, max);
        }
    }

    return max;
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
