#include <string>
#include <algorithm>
#include <iostream>
#include <map>

auto romanToInt(std::string s) -> int {
    std::map<char, int> roman_values = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    std::reverse(s.begin(), s.end());

    int total = 0;
    int prev = 0;

    for (int i = 0; i < s.length(); i++) {
        int curr = roman_values[s[i]];

        if (prev > curr) {
            total -= roman_values[s[i]];
        } else {
            total += roman_values[s[i]];
        }

        prev = curr;
    }

    return total;
}

auto main() -> int {
    std::cout << romanToInt("MMCCCXCIV") << std::endl;
}