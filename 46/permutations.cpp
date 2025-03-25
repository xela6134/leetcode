#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> perms = {{}};

    // Initial: perms = {{}}
    //   First: perms = {{1}}
    //  Second: perms = {{1,2}, {2,1}}
    //   Third: perms = {{3,2,1}, {2,3,1}, {2,1,3}, {3,1,2}, {1,3,2}, {1,2,3}}

    for (int num : nums) {
        std::vector<std::vector<int>> new_perms;
        for (const auto& p : perms) {
            for (int i = 0; i <= p.size(); i++) {
                std::vector<int> p_copy = p;
                p_copy.insert(p_copy.begin() + i, num);
                new_perms.push_back(p_copy);
            }
        }
        perms = new_perms;
    }
    return perms;
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
