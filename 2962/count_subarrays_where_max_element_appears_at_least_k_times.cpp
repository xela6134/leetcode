#include <iostream>
#include <vector>

long long countSubarrays(std::vector<int>& nums, int k) {
    int maxVal = *max_element(nums.begin(), nums.end());
    int n = nums.size();
    long long ans = 0;
    int left = 0;
    int count = 0;      // count of maxVals of subarrays

    for (int right = 0; right < n; ++right) {
        if (nums[right] == maxVal) {
            ++count;
        }

        while (count >= k) {
            if (nums[left] == maxVal) {
                --count;
            }
            ++left;
        }

        ans += left;
    }

    return ans;
}

int main() {

}
