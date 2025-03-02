#include <vector>
#include <iostream>

bool increasingTriplet(std::vector<int>& nums) {
    int small = 2147483647;
    int mid = 2147483647;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < small) {
            small = nums[i];
        } else if (nums[i] < mid) {
            mid = nums[i];
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<int> nums1 = {1,2,3,4,5};
    std::vector<int> nums2 = {5,4,3,2,1};
    std::vector<int> nums3 = {2,1,5,0,6};

    std::cout << std::boolalpha << increasingTriplet(nums1) << std::endl;
    std::cout << std::boolalpha << increasingTriplet(nums2) << std::endl;
    std::cout << std::boolalpha << increasingTriplet(nums3) << std::endl;
}
