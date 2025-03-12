#include <iostream>
#include <vector>

// auto twoSum(std::vector<int>& numbers, int target) -> std::vector<int> {
//     int left = 0;
//     int right = 1;
//     std::vector<int> result;

//     while (right < numbers.size() and left < right) {
//         int sum = numbers[left] + numbers[right];

//         if (sum > target) {
//             ++left;
//         } else if (sum < target) {
//             ++right;
//         } else {
//             result.push_back(++left);
//             result.push_back(++right);
//         }
//     }

//     return result;
// }

auto twoSum(std::vector<int>& numbers, int target) -> std::vector<int> {
    int left = 0;
    int right = numbers.size() - 1;
    std::vector<int> result;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum > target) {
            --right;
        } else if (sum < target) {
            ++left;
        } else {
            result.push_back(++left);
            result.push_back(++right);
        }
    }

    return result;
}

void print_result(std::vector<int>& numbers) {
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums1 = {2,7,11,15};
    std::vector<int> nums2 = {2,3,4};
    std::vector<int> nums3 = {-1,0};

    auto result1 = twoSum(nums1, 9);
    auto result2 = twoSum(nums2, 6);
    auto result3 = twoSum(nums3, -1);

    print_result(result1);
    print_result(result2);
    print_result(result3);
}
