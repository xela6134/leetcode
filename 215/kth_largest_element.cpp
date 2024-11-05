#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <iostream>

// Priority Queue Solution
// int findKthLargest(std::vector<int>& nums, int k) {
//     std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

//     for (int& num : nums) {
//         min_heap.push(num);

//         if (min_heap.size() > k) {
//             min_heap.pop();
//         }
//     }

//     return min_heap.top();
// }

// Quickselect Solution
// int partition(std::vector<int>& nums, int left, int right) {
//     // Pivot: Far right
//     int pivot = nums[right];
//     int i = left - 1;

//     for (int j = left; j < right; ++j) {
//         if (nums[j] < pivot) {
//             ++i;
//             std::swap(nums[i], nums[j]);
//         }
//     }

//     // Place index in right position
//     std::swap(nums[i + 1], nums[right]);
//     return i + 1;
// }

// int quickselect(std::vector<int>& nums, int k_smallest, int left, int right) {
//     if (left <= right) {
//         int pivot_index = partition(nums, left, right);

//         if (pivot_index == k_smallest) {
//             return nums[pivot_index];
//         } else if (pivot_index > k_smallest) {
//             return quickselect(nums, k_smallest, left, pivot_index - 1);
//         } else {
//             return quickselect(nums, k_smallest, pivot_index + 1, right);
//         }
//     }

//     return -1;
// }

// int findKthLargest(std::vector<int>& nums, int k) {
//     int n = nums.size();
//     // Find the (n - k)th smallest element to get the kth largest
//     return quickselect(nums, n - k, 0, n - 1);
// }

// Counting sort
int findKthLargest(std::vector<int>& nums, int k) {
    int min_value = INT_MAX;
    int max_value = INT_MIN;
    
    for (int& num : nums) {
        min_value = std::min(min_value, num);
        max_value = std::max(max_value, num);
    }
    
    // If min_value = 3, max_value = 9
    // index - value is
    // 0 1 2 3 4 5 6
    // 3 4 5 6 7 8 9
    std::vector<int> count(max_value - min_value + 1);
    for (int& num : nums) {
        count[num - min_value]++;
    }
    
    int remain = k;
    for (int num = count.size() - 1; num >= 0; num--) {
        remain -= count[num];

        if (remain <= 0) {
            return num + min_value;
        }
    }
    
    return -1;
}

auto main() -> int {
    std::vector<int> nums1 = {3,2,1,5,6,4};
    std::cout << findKthLargest(nums1, 2) << std::endl;

    std::vector<int> nums2 = {3,2,3,1,2,4,5,5,6};
    std::cout << findKthLargest(nums2, 4) << std::endl;
}
