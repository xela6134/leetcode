#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

auto topKFrequent(std::vector<int>& nums, int k) -> std::vector<int> {
    // 1. Make a map
    std::unordered_map<int, int> count;
    for (int& num : nums) {
        ++count[num];
    }

    // 2. Get 'most frequent elements'
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> min_heap;
    for (const auto& [num, freq] : count) {
        min_heap.emplace(freq, num);
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }

    // 3. Change map to vector and return
    std::vector<int> result;
    while (not min_heap.empty()) {
        result.push_back(min_heap.top().second);
        min_heap.pop();
    }

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
