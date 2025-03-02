#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

int maxOperations(std::vector<int>& nums, int k) {
    int operations = 0;

    std::unordered_map<int, int> num_count;

    for (int i = 0; i < nums.size(); ++i) {
        if (num_count[k - nums[i]] > 0) {
            --num_count[k - nums[i]];
            ++operations;
        } else {
            ++num_count[nums[i]];
        }
    }

    return operations;
}

int main() {
    std::vector<int> nums1 = {1,2,3,4};
    std::cout << maxOperations(nums1, 5) << std::endl;

    std::vector<int> nums2 = {3,1,3,4,3};
    std::cout << maxOperations(nums2, 6) << std::endl;
}
