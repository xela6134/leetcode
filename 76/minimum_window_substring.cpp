#include <string>
#include <iostream>
#include <unordered_map>
#include <climits>

auto minWindow(std::string s, std::string t) -> std::string {
    int left = 0;
    int right = 0;
    int max = s.size() - 1;
    std::string result = "";
    int max_size = INT_MAX;

    std::unordered_map<char, int> frequency;

    while (left != max && right != max) {
        // Check if all characters exist
        std::unordered_map<char, int> curr_frequency = frequency;

        bool chars_exist = true;
        for (char c : t) {
            if (curr_frequency[c] <= 0) {
                chars_exist = false;
            }
            curr_frequency[c]--;
        }

        if (chars_exist) {
            std::string substring = s.substr(left, right - left + 1);
            if (substring.length() < max_size) {
                result = substring;
                max_size = substring.length();
            }

            frequency[t[left]]--;
            ++left;
        } else {
            frequency[t[right]]++;
            ++right;
        }
    }

    return result;
}

auto main() -> int {
    std::cout << minWindow("ADOBECODEBANC", "ABC") << std::endl;
    std::cout << minWindow("a", "a") << std::endl;
    std::cout << minWindow("a", "aa") << std::endl;
    
}
