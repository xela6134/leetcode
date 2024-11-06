#include <vector>
#include <unordered_set>
#include <iostream>

int findDuplicate(std::vector<int>& nums) {
    // Phase 1: Detect the cycle. Start loop after moving once
    int slow = nums[0], fast = nums[0];
    slow = nums[slow];
    fast = nums[nums[fast]];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    // Phase 2: Find the entry point of the cycle (duplicate number)
    // Proof of this is in Neetcode video (https://youtu.be/wjYnzkAhcNk?si=GMZNNLBnSbs1wyd9)

    // Reset slow to the start of the array
    slow = nums[0];

    // Move both pointers one step at a time
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    
    return slow; // The duplicate number
}

auto main() -> int {
    std::vector<int> nums;

    nums = {1,3,4,2,2};
    std::cout << findDuplicate(nums) << std::endl;

    nums = {3,1,3,4,2};
    std::cout << findDuplicate(nums) << std::endl;

    nums = {3,3,3,3,3};
    std::cout << findDuplicate(nums) << std::endl;
}
