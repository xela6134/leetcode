#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>

int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> characters;
    int left = 0;
    int max_length = 0;

    for (int right = 0; right < s.size(); ++right) {
        // Increment left until duplicate elements are gone
        while (characters.contains(s[right])) {
            characters.erase(s[left]);
            ++left;
        }

        characters.insert(s[right]);
        max_length = std::max(max_length, right - left + 1);
    }

    return max_length;
}

auto main() -> int {
    std::string str1 = "abcabcbb";  // abc: 3
    std::string str2 = "bbbbb";     // b  : 1
    std::string str3 = "pwwkew";    // wke: 3
    std::cout << lengthOfLongestSubstring(str1) << std::endl;
    std::cout << lengthOfLongestSubstring(str2) << std::endl;
    std::cout << lengthOfLongestSubstring(str3) << std::endl;
}
