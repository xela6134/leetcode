#include <iostream>
#include <vector>
#include <algorithm>

int numRescueBoats(std::vector<int> people, int limit) {
    std::sort(people.begin(), people.end());
    int boats = 0;
    int light = 0;
    int heavy = people.size() - 1;
    
    while (light <= heavy) {
        if (people[light] + people[heavy] <= limit) {
            ++light;
        }
        --heavy;
        ++boats;
    }
    
    return boats;
}

int main() {
    std::cout << numRescueBoats({1,2}, 3) << std::endl;
    std::cout << numRescueBoats({3,2,2,1}, 3) << std::endl;
    std::cout << numRescueBoats({3,5,3,4}, 5) << std::endl;
    std::cout << numRescueBoats({1,2,2,2,2,2,2,2,3,4,5,6}, 6) << std::endl;
}
