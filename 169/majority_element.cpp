#include <vector>
#include <iostream>

int majorityElement(std::vector<int>& nums) {
    if (nums.size() == 1) return nums[0];

    int count = 1;
    int majority = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == majority) {
            ++count;
        } else {
            --count;
            if (count == 0) {
                majority = nums[i];
                count = 1;
            }
        }
    }

    return majority;
}

auto main() -> int {
    std::vector<int> vec1 = {3,2,3};
    std::cout << majorityElement(vec1) << std::endl;

    std::vector<int> vec2 = {2,2,1,1,1,2,2};
    std::cout << majorityElement(vec2) << std::endl;
}
