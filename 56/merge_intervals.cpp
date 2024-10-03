#include <vector>
#include <iostream>
#include <algorithm>

auto merge(std::vector<std::vector<int>>& intervals) -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> result;

    if (intervals.empty()) return result;

    std::sort(intervals.begin(), intervals.end());

    bool first = true;
    std::vector<int> curr = intervals[0];

    for (std::vector<int> interval : intervals) {
        // Skipping first interval
        if (first) {
            first = false;
            continue;
        }

        // Overlapping case
        if (curr[0] < interval[0] and curr[1] > interval[1]) continue;

        if (curr[1] >= interval[0]) {
            // If curr and interval are mergeable
            curr[1] = interval[1];
        } else {
            // If curr and interval are not mergeable
            result.push_back(curr);
            curr = interval;
        }
    }

    result.push_back(curr);
    return result;
}

auto print_result(std::vector<std::vector<int>> intervals) {
    for (std::vector<int> interval : intervals) {
        std::cout << interval[0] << " " << interval[1] << std::endl;
    }
}

auto main() -> int {
    std::vector<std::vector<int>> intervals1 = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };
    auto merged1 = merge(intervals1);
    print_result(merged1);
    std::cout << std::endl;

    std::vector<std::vector<int>> intervals2 = {
        {1,4},
        {4,5}
    };
    auto merged2 = merge(intervals2);
    print_result(merged2);
    std::cout << std::endl;
}
