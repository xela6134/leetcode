#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

double findMaxAverage(std::vector<int>& nums, int k) {
    // Make initial sum
    // Iterate using while loop
    // Do one plus and minus each for efficiency

    int curr_sum = std::accumulate(nums.begin(), nums.begin() + k, 0);
    int max = curr_sum;

    for (int i = k; i < nums.size(); ++i) {
        curr_sum -= nums[i - k];
        curr_sum += nums[i];

        max = std::max(max, curr_sum);
    }

    double result = static_cast<double>(max) / k;
    return result;
}

int main() {
    std::vector<int> nums1 = {1,12,-5,-6,50,3};
    std::cout << findMaxAverage(nums1, 4) << std::endl;

    std::vector<int> nums2 = {5};
    std::cout << findMaxAverage(nums2, 1) << std::endl;
}
