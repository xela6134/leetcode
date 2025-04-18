#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    // 0,0,1,1,1,2,2,3,3,4
    int index = 1;

    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 and nums[i-1] != nums[i]) {
            nums[index] = nums[i];
            ++index;
        }
    }

    return index - 1;
}

int main() {

}
