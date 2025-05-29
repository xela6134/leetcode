#include <iostream>
#include <vector>

void nextPermutation(std::vector<int>& nums) {
    // keep the left side of the number as similar as possible
    // make the smallest possible increase just after the point where the permutation starts descending from the end

    // start from 2nd last element (so we have i and i+1)
    int i = nums.size() - 2;

    // Step 1: Find first decreasing element from the end (where nums[i] < nums[i + 1])
    while (i >= 0 and nums[i] >= nums[i + 1]) {
        i--;
    }

    int j = nums.size() - 1;
    if (i >= 0) {
        // Step 2: Find element just larger than nums[i] (nums[j] > nums[i])
        while (nums[j] <= nums[i]) {
            j--;
        }

        // Step 3: Swap
        std::swap(nums[i], nums[j]);
    }

    // 1 2 3 6 5 4
    // 1 2 4 6 5 3 -> make the 'smallest change' possible
    // 1 2 4 3 5 6 -> afterwards reverse the end part to make it as small as possible

    // std::cout << "i: " << i << std::endl;
    // std::cout << "j: " << j << std::endl;
    // for (int num : nums) {
    //     std::cout << num << ' ';
    // }
    // std::cout << std::endl;

    // Step 4: Reverse the suffix
    std::reverse(nums.begin() + i + 1, nums.end());
}

int main() {

}
