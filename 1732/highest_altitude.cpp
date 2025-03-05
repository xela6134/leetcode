#include <iostream>
#include <vector>
#include <algorithm>

int largestAltitude(std::vector<int>& gain) {
    int curr_altitude = 0;
    int max_altitude = 0;

    // For each difference, calculate the current altitude.

    for (const int& diff : gain) {
        curr_altitude += diff;
        max_altitude = std::max(max_altitude, curr_altitude);
    }

    return max_altitude;
}

int main() {
    std::vector<int> gain1 = {-5,1,5,0,-7};
    std::cout << largestAltitude(gain1) << std::endl;

    std::vector<int> gain2 = {-4,-3,-2,-1,4,3,2};
    std::cout << largestAltitude(gain2) << std::endl;
}
