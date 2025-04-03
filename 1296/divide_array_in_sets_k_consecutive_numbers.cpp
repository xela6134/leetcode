#include <iostream>
#include <vector>
#include <unordered_map>

bool isPossibleDivide(std::vector<int>& nums, int k) {
    int size = nums.size();
    if (size % k != 0) return false;

    // Get count
    std::unordered_map<int, int> count;
    for (const int& num : nums) {
        ++count[num];
    }

    // Loop through numbers
    std::sort(nums.begin(), nums.end());
    for (const int& num : nums) {
        if (count[num] <= 0) continue;

        // Start loop
        for (int i = num; i < num + k; ++i) {
            if (count[i] <= 0) return false;
            --count[i];
        }
    }

    return true;
}

int main() {

}
