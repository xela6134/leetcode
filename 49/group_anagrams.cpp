#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

auto groupAnagrams(std::vector<std::string>& strs) -> std::vector<std::vector<std::string>> {
    auto anagram_map = std::unordered_map<std::string, std::vector<std::string>>{};

    for (const std::string& str : strs) {
        std::string sorted = str;
        std::sort(sorted.begin(), sorted.end());

        anagram_map[sorted].push_back(str);
    }

    auto result = std::vector<std::vector<std::string>>{};

    for (const auto& pair : anagram_map) {
        result.push_back(pair.second);
    }

    return result;
}

auto main() -> int {
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> groupedAnagrams = groupAnagrams(strs);

    // Print the result
    for (const auto& group : groupedAnagrams) {
        for (const std::string& word : group) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
