#include <vector>
#include <iostream>

void sortColors(std::vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            std::swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            std::swap(nums[mid], nums[high]);
            high--;
        }
    }
}

auto main() -> int {
    std::vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);

    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
