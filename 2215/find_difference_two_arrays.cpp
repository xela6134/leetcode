#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

auto findDifference(std::vector<int>& nums1, std::vector<int>& nums2) -> std::vector<std::vector<int>> {
    std::unordered_set<int> set1;
    std::unordered_set<int> set2;
    std::vector<int> result1;
    std::vector<int> result2;

    for (int i = 0; i < nums1.size(); ++i) {
        set1.insert(nums1[i]);
    }

    for (int i = 0; i < nums2.size(); ++i) {
        set2.insert(nums2[i]);
    }

    for (auto it = set1.begin(); it != set1.end(); ++it) {
        if (set2.find(*it) == set2.end()) {
            result1.push_back(*it);
        }
    }

    for (auto it = set2.begin(); it != set2.end(); ++it) {
        if (set1.find(*it) == set1.end()) {
            result2.push_back(*it);
        }
    }

    std::sort(result1.begin(), result1.end());
    std::sort(result2.begin(), result2.end());

    return {result1, result2};
}

void print_result(std::vector<std::vector<int>>& result) {
    for (const std::vector<int>& row : result) {
        for (const int& num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<int> nums1 = {1,2,3};
    std::vector<int> nums2 = {2,4,6};
    std::vector<std::vector<int>> result1 = findDifference(nums1, nums2);
    print_result(result1);

    std::vector<int> nums3 = {1,2,3,3};
    std::vector<int> nums4 = {1,1,2,2};
    std::vector<std::vector<int>> result2 = findDifference(nums3, nums4);
    print_result(result2);
}
