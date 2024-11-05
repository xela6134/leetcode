#include <vector>
#include <iostream>

auto productExceptSelf(std::vector<int>& nums) -> std::vector<int> {
    // -1, 1, 0, -3, 3
    int n = nums.size();
    
    std::vector<int> left(n);
    std::vector<int> right(n);
    
    int left_prod = 1;
    for (int i = 0; i < n; ++i) {
        left_prod = left_prod * nums[i];
        left[i] = left_prod;
    }

    int right_prod = 1;
    for (int i = n - 1; i >= 0; --i) {
        right_prod = right_prod * nums[i];
        right[i] = right_prod;
    }

    std::vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        // Far left
        if (i == 0) {
            result[i] = right[i + 1];
        }

        // Far right
        else if (i == n - 1) {
            result[i] = left[i - 1];
        }

        // Everything else
        else {
            result[i] = left[i - 1] * right[i + 1];
        }
    }

    return result;
}

auto main() -> int {
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> result;

    result = productExceptSelf(nums);
    for (int& num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    nums = {-1, 1, 0, -3, 3};
    result = productExceptSelf(nums);
    for (int& num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
