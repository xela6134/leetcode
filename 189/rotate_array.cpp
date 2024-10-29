#include <vector>
#include <algorithm>
#include <iostream>

void print_result(std::vector<int>& nums) {
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    // 7,6,5,4,3,2,1
    std::reverse(nums.begin(), nums.end());

    // 5,6,7,4,3,2,1
    std::reverse(nums.begin(), nums.begin() + k);

    // 5,6,7,1,2,3,4
    std::reverse(nums.begin() + k, nums.end());
}

auto main() -> int {
    std::vector<int> nums = {1,2,3,4,5,6,7};
    rotate(nums, 3);
    std::cout << "This is the result -" << std::endl;
    print_result(nums);
}
