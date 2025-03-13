#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (target < nums[mid]) {
            right = mid - 1;
        } else if (target > nums[mid]) {
            left = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    std::vector<int> nums = {-1,0,3,5,9,12};
    std::cout << search(nums, 9) << std::endl;
    std::cout << search(nums, 2) << std::endl;
}
