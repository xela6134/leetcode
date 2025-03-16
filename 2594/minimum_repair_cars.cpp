#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

long long repairCars(std::vector<int>& ranks, int cars) {
    std::sort(ranks.begin(), ranks.end());

    long long min = 1;    
    long long max = *min_element(ranks.begin(), ranks.end()) * (long long)cars * cars;

    long long left = 1, right = max;
    long long cars_ = static_cast<long long>(cars);
    long long min_time = max;

    while (left <= right) {
        long long curr_time = (left + right) / 2;

        // This takes O(n) time, where n is size of ranks.

        // 1. For each element, calculate sqrt(curr / ranks[0])
        // 2. Add to max_cars_fixed
        // 3. If max_cars_fixed >= cars, search left. Otherwise search right
        long long max_cars_fixed = 0;
        for (int i = 0; i < ranks.size(); ++i) {
            long long cars_fixed = static_cast<long long>(std::floor(std::sqrt(curr_time / ranks[i])));
            max_cars_fixed += cars_fixed;
            // std::cout << max_cars_fixed << ", " << cars_fixed << std::endl;
        }

        std::cout << left << ", " << right << ", " << curr_time << ": " << max_cars_fixed << std::endl;

        if (max_cars_fixed >= cars_) {
            min_time = std::min(curr_time, min_time);
            right = curr_time - 1;
        } else {
            left = curr_time + 1;
        }
    }

    return min_time;
}

int main() {
    std::vector<int> ranks1 = {4,2,3,1};
    std::vector<int> ranks2 = {5,1,8};

    std::cout << repairCars(ranks1, 10) << std::endl;
    std::cout << repairCars(ranks2, 6) << std::endl;
}
