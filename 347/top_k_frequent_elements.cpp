#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <algorithm>

auto topKFrequent(std::vector<int>& nums, int k) -> std::vector<int> {
    // 1. Make a map
    std::unordered_map<int, int> frequencies;

    for (int num : nums) {
        ++frequencies[num];
    }

    // 2. Calculate frequency
    // Needs to be a min queue because we need to only get the largest elements to stay
    // Stored in { freq, num } format
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> queue;

    for (const auto& [num, freq] : frequencies) {
        queue.push(std::make_pair(freq, num));
        if (queue.size() > k) queue.pop();
    }

    // 3. Return result
    std::vector<int> result;
    while (not queue.empty()) {
        result.push_back(queue.top().second);
        queue.pop();
    }

    std::sort(result.begin(), result.end());

    return result;
}

auto main() -> int {
    std::vector<int> nums = {1,1,1,2,2,3};
    auto result = topKFrequent(nums, 2);
    for (int& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
