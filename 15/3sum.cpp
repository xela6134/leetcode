#include <vector>
#include <algorithm>
#include <iostream>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;

    for (int i = 0; i < nums.size() - 2; ++i) {
        // Skip duplicates for starting number
        if (i > 0 and nums[i] == nums[i - 1]) continue;
        if (nums[i] > 0) break;

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum < 0) {
                ++left;
            } else if (sum > 0) {
                --right;
            } else {
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicates for left and right
                while (left < right and nums[left] == nums[left + 1]) ++left;
                while (left < right and nums[right] == nums[right - 1]) --right;

                ++left;
                --right;
            }
        }
    }

    return result;
}

auto main() -> int {
    auto nums = std::vector<int>{-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> vecs = threeSum(nums);

    for (const auto& vec : vecs) {
        for (const auto& num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}
