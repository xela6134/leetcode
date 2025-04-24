#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {
    std::sort(boxTypes.begin(), boxTypes.end(), [](const auto& a, const auto& b) {
        return a[1] > b[1];
    });

    int totalUnits = 0;

    for (const auto& box : boxTypes) {
        int boxesToTake = std::min(truckSize, box[0]);
        totalUnits += boxesToTake * box[1];
        truckSize -= boxesToTake;
        
        if (truckSize == 0) break;
    }

    return totalUnits;
}

int main() {

}
