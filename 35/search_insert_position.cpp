#include <iostream>
#include <vector>

int searchInsert(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

auto main() -> int {
    std::vector<int> nums1 = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    
    std::cout << searchInsert(nums1, 11) << std::endl;
    std::cout << searchInsert(nums1, 10) << std::endl;
    std::cout << searchInsert(nums1, 9) << std::endl;
}
