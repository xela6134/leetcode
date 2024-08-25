#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>

auto lengthOfLongestSubstring(std::string s) -> int {
    int left = 0;
    int max_length = 0;
    auto char_set = std::unordered_set<char>{};

    for (int right = 0; right < s.size(); right++) {
        while (char_set.contains(s[right])) {
            char_set.erase(s[left]);
            left++;
        }

        char_set.insert(s[right]);
        max_length = std::max(max_length, right - left + 1);
    }

    return max_length;
}

auto main() -> int {
    auto str = std::string("pwwkew");
    std::cout << lengthOfLongestSubstring(str) << std::endl;
}
