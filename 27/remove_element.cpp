#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    int left = 0;
    int right = nums.size() - 1;

    // 0 1 2 2 3 0 4 2
    while (left <= right) {
        if (nums[left] == val) {
            nums[left] = nums[right];
            --right;
        } else {
            ++left;
        }
    }

    return left;
}

int main() {

}
