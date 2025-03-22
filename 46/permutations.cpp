#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

void generate(std::vector<int>& used, std::vector<int>& unused, std::vector<std::vector<int>>& result) {
    if (unused.empty()) {
        result.push_back(used);
        return;
    }

    for (int num : unused) {
        std::vector<int> new_used = used;
        new_used.push_back(num);

        std::vector<int> new_unused = unused;
        new_unused.erase(std::remove(new_unused.begin(), new_unused.end(), num), new_unused.end());

        generate(new_used, new_unused, result);
    }
}

auto permute(std::vector<int>& nums) -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> result;

    std::vector<int> used;
    std::vector<int> unused = nums;

    generate(used, unused, result);

    return result;
}

auto print_result(std::vector<std::vector<int>> result) {
    for (auto vec : result) {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

auto main() -> int {
    auto nums = std::vector<int>{1, 2, 3, 4};
    auto result = permute(nums);
    print_result(result);
}
