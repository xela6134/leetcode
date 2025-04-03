#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

bool isNStraightHand(std::vector<int> hand, int groupSize) {
    // 1,2,3,6,2,3,4,7,8
    // 1,2,2,3,3,4,6,7,8

    // 1: 1 | 0 | 0 | 0
    // 2: 2 | 1 | 0 | 0
    // 3: 2 | 1 | 0 | 0
    // 4: 1 | 1 | 0 | 0
    // 6: 1 | 1 | 1 | 0
    // 7: 1 | 1 | 1 | 0
    // 8: 1 | 1 | 1 | 0

    // 1,2,3,4,5,6,7,9
    // 1: 1 | 0 | 
    // 2: 1 | 0 | 
    // 3: 1 | 0 | 
    // 4: 1 | 0 | 
    // 5: 1 | 1 | 
    // 6: 1 | 1 | 
    // 7: 1 | 1 | 
    // 9: 1 | 1 | 

    // 1. Get the count
    // 2. Each round, delete the count of numbers
    // 3. If failed to delete, return false.
    //    Otherwise (proceed up to end of group)

    int size = hand.size();
    if (size % groupSize != 0) return false;

    // Get count
    std::unordered_map<int, int> count;
    for (const int& num : hand) {
        ++count[num];
    }

    // Loop through numbers
    std::sort(hand.begin(), hand.end());
    for (const int& num : hand) {
        if (count[num] <= 0) continue;

        // Start loop
        for (int i = num; i < num + groupSize; ++i) {
            if (count[i] <= 0) return false;
            --count[i];
        }
    }

    return true;
}

int main() {
    std::cout << std::boolalpha << isNStraightHand({3,2,1,2,3,4,3,4,5,9,10,11}, 3) << std::endl;
    std::cout << std::boolalpha << isNStraightHand({1,2,3,4,5}, 4) << std::endl;
    std::cout << std::boolalpha << isNStraightHand({1,2,3,4,5,6,8,9}, 4) << std::endl;
    std::cout << std::boolalpha << isNStraightHand({1,2,3,4,5,6,8,9}, 2) << std::endl;
}
