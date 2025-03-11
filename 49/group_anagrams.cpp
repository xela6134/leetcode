#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

auto groupAnagrams(std::vector<std::string>& strs) -> std::vector<std::vector<std::string>> {
    std::unordered_map<std::string, std::vector<std::string>> strings;

    for (const auto& str : strs) {
        std::string sorted = str;
        std::sort(sorted.begin(), sorted.end());

        strings[sorted].push_back(str);
    }

    std::vector<std::vector<std::string>> result;
    for (const auto& [key, val] : strings) {
        result.push_back(val);
    }

    return result;
}

auto main() -> int {
    std::vector<std::string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> grouped = groupAnagrams(words);

    for (const auto& group : grouped) {
        for (const std::string& word : group) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
