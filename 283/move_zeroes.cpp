#include <vector>
#include <algorithm>
#include <iostream>

void print_vec(std::vector<int>& nums) {
    for (int& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void moveZeroes(std::vector<int>& nums) {
    // Push non-zero elements to forward
    // Keep track of 0s
    //    0 1 0 3 2
    // 
    // 0. 0 1 0 3 2
    // 1. 1 0 0 3 2
    // 2. 1 0 0 3 2
    // 3. 1 3 0 0 2
    // 4. 1 3 2 0 0

    int zero_index = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            std::swap(nums[i], nums[zero_index]);
            ++zero_index;
        }
    }
}

auto main() -> int {
    std::vector<int> nums = {0,1,0,3,8};
    // 0 1 0 3 8
    // 1 0 0 3 8
    // 1 3 0 0 8
    // 1 3 8 0 0
    
    moveZeroes(nums);
    print_vec(nums);
}