#include <vector>
#include <algorithm>
#include <iostream>

auto searchRange(std::vector<int>& nums, int target) -> std::vector<int> {
    if (nums.empty()) return {-1, -1};

    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    int firstPos = left;

    if (firstPos >= nums.size() || nums[firstPos] != target) {
        return {-1, -1};
    }

    right = static_cast<int>(nums.size()) - 1;
    while (left <= right) {
        mid = (left + right) / 2;

        if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    int lastPos = right;

    return {firstPos, lastPos};
}

auto main() -> int {
    std::vector nums = {5,7,7,8,8,10};
    std::vector<int> result = searchRange(nums, 8);
    std::cout << result[0] << ", " << result[1] << std::endl;
}
