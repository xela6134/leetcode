#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int findMin(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    int smallest = INT_MAX;


    // Need a greedy algorithm which tries to find the smallest possible element
    // 0 1 2 3 4 5 6
    // -------------
    // 1 2 3 4 5 6 7
    // 2 3 4 5 6 7 1
    // 3 4 5 6 7 1 2
    // 4 5 6 7 1 2 3
    // 5 6 7 1 2 3 4
    // 6 7 1 2 3 4 5
    // 7 1 2 3 4 5 6
    while (left <= right) {
        int mid = (left + right) / 2;
        smallest = std::min(nums[mid], smallest);

        // Look through right
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } 

        // Look through left
        else {
            right = mid - 1;
        }
    }

    return smallest;
}

int main() {

}
