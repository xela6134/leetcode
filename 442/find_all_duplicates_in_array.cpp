#include <iostream>
#include <vector>

std::vector<int> findDuplicates(std::vector<int>& nums) {
    std::vector<int> result;

    // Each number can be used as an index (after subtracting 1)

    // 4 3 2 7 8 2 3 1
    // index=3, nums[index]=7
    // 4 3 2 -7 8 2 3 1
    // index=2, nums[index]=2
    // 4 3 -2 -7 8 2 3 1
    // index=1, nums[index]=3
    // 4 -3 -2 -7 8 2 3 1
    // index=6, nums[index]=3
    // 4 -3 -2 -7 8 2 -3 1
    // index=7, nums[index]=2
    // 4 -3 -2 -7 8 2 -3 -1
    // index=1, nums[index]=-3
    // 
    for (int num : nums) {
        int index = abs(num) - 1;
        if (nums[index] < 0) {
            result.push_back(abs(num));
        } else {
            nums[index] = -nums[index];
        }
    }
    
    return result;
}

int main() {

}
