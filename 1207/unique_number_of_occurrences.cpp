#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

bool uniqueOccurrences(std::vector<int>& arr) {
    std::unordered_map<int, int> num_map;
    std::unordered_set<int> num_set;

    for (const int& num : arr) {
        ++num_map[num];
    }

    for (const auto& [key, val] : num_map) {
        if (num_set.find(val) == num_set.end()) {
            num_set.insert(val);
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    std::vector<int> arr1 = {1,2,2,1,1,3};
    std::vector<int> arr2 = {1,2};
    std::vector<int> arr3 = {-3,0,1,-3,1,1,1,-3,10,0};

    std::cout << std::boolalpha << uniqueOccurrences(arr1) << std::endl;
    std::cout << std::boolalpha << uniqueOccurrences(arr2) << std::endl;
    std::cout << std::boolalpha << uniqueOccurrences(arr3) << std::endl;
}
