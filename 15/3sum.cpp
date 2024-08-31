#include <vector>
#include <algorithm>
#include <iostream>

auto threeSum(std::vector<int>& nums) -> std::vector<std::vector<int>> {
    std::sort(nums.begin(), nums.end());
    auto vectors = std::vector<std::vector<int>>{};

    for (int i = 0; i < nums.size() - 2; ++i) {
        if (i > 0 and nums[i] == nums[i - 1]) continue;
        if (nums[i] > 0) break;

        int target = nums[i];
        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = target + nums[left] + nums[right];

            if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            } else {
                vectors.push_back({target, nums[left], nums[right]});

                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            }
        }
    }

    std::sort(vectors.begin(), vectors.end());
    auto last = std::unique(vectors.begin(), vectors.end());
    vectors.erase(last, vectors.end());

    return vectors;
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
