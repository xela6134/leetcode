#include <iostream>
#include <vector>
#include <algorithm>

int maxArea(std::vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_water = 0;

    while (left < right) {
        int curr_water = std::min(height[left], height[right]) * (right - left);
        max_water = std::max(max_water, curr_water);

        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }

    return max_water;
}

int main() {
    std::vector<int> heights1 = {1,8,6,2,5,4,8,3,7};
    std::cout << maxArea(heights1) << std::endl;

    std::vector<int> heights2 = {1,1};
    std::cout << maxArea(heights2) << std::endl;

    std::vector<int> heights3 = {8,7,2,1};
    std::cout << maxArea(heights3) << std::endl;
}
