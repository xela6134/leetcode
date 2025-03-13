#include <iostream>
#include <vector>
#include <algorithm>

// int maxNonDecreasingLength(std::vector<int>& nums1, std::vector<int>& nums2) {
//     // 1, 3, 2, 1
//     // 2, 2, 3, 4
//     // 1, 2, 2, 4

//     // 2, 3, 1
//     // 1, 2, 1
//     // 1, 2, 1

//     // 1, 1
//     // 2, 2
//     // 1, 1

//     //   1. Only grab element(s) that are smaller than or equal to last choice
//     // 2-1. If existX: Start from scratch, curr = 0
//     // 2-2. If exist : Choose the smaller

//     int curr = 0, max = 0;
//     int last_chosen = 0;

//     for (int i = 0; i < nums1.size(); ++i) {
//         // 1. Only grab elements smaller than last choice
//         std::vector<int> smaller;
//         if (nums1[i] >= last_chosen) smaller.push_back(nums1[i]);
//         if (nums2[i] >= last_chosen) smaller.push_back(nums2[i]);

//         // 2-1. If no elements are in smaller
//         if (smaller.empty()) {
//             curr = 0;
//             last_chosen = std::min(nums1[i], nums2[i]);
//         } 
        
//         // 2-2. If only one element exists
//         else if (smaller.size() == 1) {
//             last_chosen = smaller[0];
//         } 
        
//         // 2-3. Both elements satisfy conditon
//         else {
//             last_chosen = std::min(nums1[i], nums2[i]);
//         }

//         std::cout << last_chosen << ", ";

//         ++curr;
//         max = std::max(curr, max);
//     }

//     std::cout << std::endl;
//     return max;
// }

int maxNonDecreasingLength(std::vector<int>& nums1, std::vector<int>& nums2) {
    // - 1, 3, 2, 1
    // - 2, 2, 3, 4
    // > 1, 2, 2, 4 (4)

    // 1 | 2 | 3 | 1
    // 1 | 2 | 3 | 4

    // - 11, 7, 7, 9
    // - 19,19, 1, 7
    // > 11, 7, 7, 9 (3)

    // 1 | 1 | 2 | 3
    // 1 | 2 | 1 | 3

    // Let dp[i][0] be the length of the longest non-decreasing ending with nums1[i].
    // Let dp[i][1] be the length of the longest non-decreasing ending with nums2[i].
    
    // Initialize dp[i][0] and dp[i][1] to 1.

    // If nums1[i] >= nums1[i - 1], then dp[i][0] may be dp[i - 1][0] + 1. 
    // If nums1[i] >= nums2[i - 1], then dp[i][0] may be dp[i - 1][1] + 1. 
    // Perform a similar calculation for nums2[i] and dp[i][1].

    int maxLen = 1, prev_dp0 = 1, prev_dp1 = 1;
        
    for (int i = 1; i < nums1.size(); ++i) {
        int cur_dp0 = 1, cur_dp1 = 1;

        if (nums1[i-1] <= nums1[i]) cur_dp0 = prev_dp0 + 1;
        if (nums2[i-1] <= nums1[i]) cur_dp0 = std::max(cur_dp0, prev_dp1 + 1);
        
        if (nums1[i-1] <= nums2[i]) cur_dp1 = prev_dp0 + 1;
        if (nums2[i-1] <= nums2[i]) cur_dp1 = std::max(cur_dp1, prev_dp1 + 1);

        maxLen = std::max({maxLen, cur_dp0, cur_dp1});
        prev_dp0 = cur_dp0;
        prev_dp1 = cur_dp1;
    }
    
    return maxLen;
}

int main() {
    std::vector<int> nums1 = {11,7,7,9};
    std::vector<int> nums2 = {19,19,1,7};

    std::cout << maxNonDecreasingLength(nums1, nums2) << std::endl;

    nums1 = {2,3,1};
    nums2 = {1,2,1};
    std::cout << maxNonDecreasingLength(nums1, nums2) << std::endl;

    nums1 = {5,3,17,5};
    nums2 = {3,6,1,17};
    std::cout << maxNonDecreasingLength(nums1, nums2) << std::endl;
}
