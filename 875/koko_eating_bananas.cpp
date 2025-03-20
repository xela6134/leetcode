#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

int minEatingSpeed(std::vector<int>& piles, int h) {
    int min = 1, max = *max_element(piles.begin(), piles.end());
    int ans = max;
    
    while (min <= max) {
        int mid = (min + max) / 2;
        int count = 0;
        for (int i : piles) {
            count += (i + mid - 1) / mid;
        }
        if (count <= h) {
            ans = mid;
            max = mid - 1;
        } else
            min = mid + 1;
    }
    return ans;
}

int main() {
    std::vector<int> piles1 = {3,6,7,11};
    std::vector<int> piles2 = {30,11,23,4,20};
    std::vector<int> piles3 = {30,11,23,4,20};

    std::cout << minEatingSpeed(piles1, 8) << std::endl;    // 4
    std::cout << minEatingSpeed(piles2, 5) << std::endl;    // 30
    std::cout << minEatingSpeed(piles3, 6) << std::endl;    // 23
}
