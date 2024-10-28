#include <vector>
#include <iostream>

int search(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) return mid;

        // Left is sorted
        if (nums[left] <= nums[mid]) {
            // Search in left
            if (nums[left] <= target and target <= nums[mid]) {
                right = mid - 1;
            }

            // Search in right
            else {
                left = mid + 1;
            }
        }

        // Right is sorted
        else {
            // Search in right
            if (nums[mid] <= target and target <= nums[right]) {
                left = mid + 1;
            }

            // Search in left
            else {
                right = mid - 1;
            }
        }
    }

    return -1;
}

auto main() -> int {
    // std::vector<int> nums = {4,5,6,7,0,1,2};

    // std::cout << search(nums, 0) << std::endl;
    // std::cout << search(nums, 3) << std::endl;

    std::vector<int> nums1 = {3,1};

    std::cout << search(nums1, 1) << std::endl;
}
