#include <vector>
#include <iostream>

int singleNumber(std::vector<int>& nums) {
    // Uses XOR.
    // a ^ a = 0
    // a ^ 0 = a
    // a ^ b ^ a = b ^ a ^ a

    int result = 0;
    for (int num : nums) {
        result ^= num;
        std::cout << result << " - ";
    }
    std::cout << std::endl;
    return result;
}

auto main() -> int {
    std::vector<int> nums1 = {2,2,1};
    std::vector<int> nums2 = {4,1,2,1,2};
    std::vector<int> nums3 = {1};
    
    std::cout << singleNumber(nums1) << std::endl;
    std::cout << singleNumber(nums2) << std::endl;
    std::cout << singleNumber(nums3) << std::endl;
}
