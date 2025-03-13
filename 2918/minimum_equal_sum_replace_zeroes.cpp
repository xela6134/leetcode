#include <iostream>
#include <vector>
#include <algorithm>

long long minSum(std::vector<int>& nums1, std::vector<int>& nums2) {
    // sum1 = 6,  zeroes1 = 2 -> min 8
    // sum2 = 11, zeroes2 = 1 -> min 12

    // sum1 = 4,  zeroes1 = 2 -> min 6
    // sum2 = 5,  zeroes2 = 0 -> min 5

    // sum1 = 5,  zeroes1 = 2 -> min 7
    // sum2 = 9,  zeroes2 = 0 -> min 9

    long long sum1 = 0, sum2 = 0;
    long long zeroes1 = 0, zeroes2 = 0;

    for (int i = 0; i < nums1.size(); ++i) {
        if (nums1[i] != 0) {
            sum1 += nums1[i];
        } else {
            ++zeroes1;
        }
    }

    for (int i = 0; i < nums2.size(); ++i) {
        if (nums2[i] != 0) {
            sum2 += nums2[i];
        } else {
            ++zeroes2;
        }
    }

    long long max1 = sum1 + zeroes1;
    long long max2 = sum2 + zeroes2;

    std::cout << sum1 << ", " << zeroes1 << std::endl;
    std::cout << sum2 << ", " << zeroes2 << std::endl;

    if (zeroes1 == 0 and zeroes2 == 0) {
        if (sum1 == sum2) return sum1;
        else return -1;
    }

    else if (zeroes1 == 0) {
        // Represents nums1 cannot grow any larger
        // If max1 < max2 return -1
        // Else return max1

        if (max1 < max2) return -1;
        else return max1;
    } 
    
    else if (zeroes2 == 0) {
        // Represents nums2 cannot grow any larger
        // If max1 > max2 return -1
        // Else return max2

        if (max1 > max2) return -1;
        else return max2;
    }
    
    else {
        return std::max(max1, max2);
    }
}

int main() {
    std::vector<int> nums1 = {0,17,20,17,5,0,14,19,7,8,16,18,6};
    std::vector<int> nums2 = {21,1,27,19,2,2,24,21,16,1,13,27,8,5,3,11,13,7,29,7};
    std::cout << minSum(nums1, nums2) << std::endl;

    nums1 = {2,0,2,0};
    nums2 = {1,4};
    std::cout << minSum(nums1, nums2) << std::endl;
}

