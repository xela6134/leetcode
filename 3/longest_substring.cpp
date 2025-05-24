#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>

int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> chars;
    int left = 0;
    int max_length = 0;

    for (int right = 0; right < s.size(); ++right) {
        while (chars.contains(s[right])) {
            chars.erase(s[left]);
            ++left;
        }

        chars.insert(s[right]);
        max_length = std::max(max_length, right - left + 1);
    }

    return max_length;
}

int main() {
    std::string str1 = "abcabcbb";  // abc: 3
    std::string str2 = "bbbbb";     // b  : 1
    std::string str3 = "pwwkew";    // wke: 3
    std::cout << lengthOfLongestSubstring(str1) << std::endl;
    std::cout << lengthOfLongestSubstring(str2) << std::endl;
    std::cout << lengthOfLongestSubstring(str3) << std::endl;
}
