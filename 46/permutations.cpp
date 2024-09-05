#include <vector>
#include <iostream>
#include <algorithm>

void generate(std::vector<int>& used, std::vector<int>& unused, std::vector<std::vector<int>>& result) {
    if (unused.empty()) {
        result.push_back(used);
        return;
    }

    for (auto it = unused.begin(); it != unused.end(); ++it) {
        auto new_used = used;
        new_used.push_back(*it);

        auto new_unused = unused;
        new_unused.erase(std::remove(new_unused.begin(), new_unused.end(), *it), new_unused.end());

        generate(new_used, new_unused, result);
    }
}

auto permute(std::vector<int>& nums) -> std::vector<std::vector<int>> {
    auto result = std::vector<std::vector<int>>{};
    auto used = std::vector<int>{};
    auto unused = nums;
    generate(used, unused, result);
    return result;
}

auto print_result(std::vector<std::vector<int>> result) {
    for (auto it1 = result.begin(); it1 != result.end(); ++it1) {
        auto vec = *it1;
        for (auto it2 = vec.begin(); it2 != vec.end(); ++it2) {
            std::cout << *it2 << " ";
        }
        std::cout << std::endl;
    }
}

auto main() -> int {
    auto nums = std::vector<int>{1, 2, 3};
    auto result = permute(nums);
    print_result(result);
}
