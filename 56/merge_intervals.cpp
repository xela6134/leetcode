#include <vector>
#include <iostream>
#include <algorithm>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end());

    std::vector<std::vector<int>> result;

    result.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i) {
        std::vector<int> last_interval = result[result.size() - 1];

        // 2 cases:
        // 1. Two intervals overlap
        // 2. No overlap

        if (intervals[i][0] <= result.back()[1]) {
            // Merge overlapping intervals
            result.back()[1] = std::max(result.back()[1], intervals[i][1]);
        } else {
            // No overlap, add as new interval
            result.push_back(intervals[i]);
        }

    }

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
