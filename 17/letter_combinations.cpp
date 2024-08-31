#include <vector>
#include <string>
#include <unordered_map>

auto letterCombinations(std::string digits) -> std::vector<std::string> {
    if (digits.length() == 0) return {};

    auto letter_map = std::unordered_map<char, std::vector<char>> {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };

    std::vector<std::string> result;
    std::string current;

    
}

auto main() -> int {

}
