#include <vector>
#include <iostream>
#include <algorithm>

bool canJump(std::vector<int>& nums) {
    // A naive solution could be initialising a vector indicating something is reachable or not
    // But all we need is the farthest variable

    int farthest = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (i > farthest) return false;
        farthest = std::max(farthest, i + nums[i]);
    }

    return true;
}

auto main() -> int {
    auto nums1 = std::vector<int>{2,3,1,1,4};           // true
    auto nums2 = std::vector<int>{3,2,1,0,4};           // false
    auto nums3 = std::vector<int>{8,2,4,4,4,9,5,2,5,8}; // 

    std::cout << std::boolalpha << canJump(nums1) << std::endl;
    std::cout << std::boolalpha << canJump(nums2) << std::endl;
    std::cout << std::boolalpha << canJump(nums3) << std::endl;
}
