#include <vector>
#include <iostream>

// O(N) space complexity
auto productExceptSelf(std::vector<int>& nums) -> std::vector<int> {
    // -1 |  1 |  0 | -3 |  3
    
    // Pre
    //  1 | -1 | -1 |  0 |  0

    // Post
    //  0 |  0 | -9 |  3 |  1

    std::vector<int> pre(nums.size(), 0);
    int prod = 1;
    for (int i = 0; i < nums.size(); ++i) {
        if (i == 0) {
            pre[i] = 1;
        } else {
            prod *= nums[i - 1];
            pre[i] = prod;
        }
    }

    std::vector<int> post(nums.size(), 0);
    prod = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
        if (i == nums.size() - 1) {
            post[i] = 1;
        } else {
            prod *= nums[i + 1];
            post[i] = prod;
        }
    }

    std::vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
        result.push_back(pre[i] * post[i]);
    }

    return result;
}

// O(1) space complexity (excluding result)
auto productExceptSelf1(std::vector<int>& nums) -> std::vector<int> {
    // -1 |  1 |  0 | -3 |  3
    
    // Pre
    //  1 | -1 | -1 |  0 |  0

    // Post
    //  0 |  0 | -9 |  3 |  1
    int n = nums.size();
    std::vector<int> result(n, 1);

    int prefix = 1;
    for (int i = 0; i < n; ++i) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}

auto main() -> int {
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> result;

    result = productExceptSelf1(nums);
    for (int& num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    nums = {-1, 1, 0, -3, 3};
    result = productExceptSelf1(nums);
    for (int& num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
