#include <vector>
#include <iostream>
#include <algorithm>

auto findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) -> double {
    return 1.0;
}

auto main() -> int {
    auto nums1 = std::vector<int>{1, 2};
    auto nums2 = std::vector<int>{3, 4};

    auto result = findMedianSortedArrays(nums1, nums2);
    std::cout << result << std::endl;
}

// auto findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) -> double {
//     auto nums = nums1;
//     int index1, index2 = 0;

//     nums.insert(nums.end(), nums2.begin(), nums2.end());
//     std::sort(nums.begin(), nums.end());

//     if (nums.size() % 2 == 0) {
//         int index1 = nums.size() / 2;
//         int index2 = index1 - 1;
//         return (static_cast<double>(nums[index1]) + static_cast<double>(nums[index2])) / 2;
//     } else {
//         int index = nums.size() / 2;
//         return static_cast<double>(nums[index]);
//     }
// }