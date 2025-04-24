#include <iostream>
#include <unordered_set>
#include <vector>

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    std::unordered_set<int> window;

    for (int i = 0; i < nums.size(); i++) {
        if (window.count(nums[i])) return true;

        window.insert(nums[i]);

        // keep the window size <= k
        if (window.size() > k) window.erase(nums[i - k]);
    }

    return false;
}

int main() {

}
