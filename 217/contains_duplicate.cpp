#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> numbers;

    for (const int& num : nums) {
        if (numbers.find(num) == numbers.end()) {
            numbers.insert(num);
        } else {
            return true;
        }
    }

    return false;
}

int main() {
    
}