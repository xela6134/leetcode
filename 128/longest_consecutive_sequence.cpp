#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

int longestConsecutive(std::vector<int>& nums) {
    if (nums.size() == 0 or nums.size() == 1) return nums.size();
    
    std::unordered_set<int> num_set(nums.begin(), nums.end());
    
    int max_size = 1;

    // set is not ordered. We need to manually lookup using find() which is O(1) time complexity
    for (int num : num_set) {
        // If start of set
        if (num_set.find(num - 1) == num_set.end()) {
            int curr_size = 1;
            int curr_num = num;
            
            // Finding takes O(1) complexity
            while (num_set.find(curr_num + 1) != num_set.end()) {
                ++curr_num;
                ++curr_size;
            }

            max_size = std::max(curr_size, max_size);
        }
    }

    return max_size;
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
