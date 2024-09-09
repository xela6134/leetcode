#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

auto backtrack(
    std::string curr, 
    std::string remaining, 
    std::unordered_map<char, std::string>& letters, 
    std::vector<std::string>& result) -> void {

    if (remaining == "") {
        result.push_back(curr);
        return;
    }

    std::string curr_chars = letters[remaining[0]];
    std::string new_remaining = remaining.substr(1);

    for (char& ch : curr_chars) {
        backtrack(curr + ch, new_remaining, letters, result);
    }
}

auto letterCombinations(std::string digits) -> std::vector<std::string> {
    if (digits.length() == 0) return {};

    auto letters = std::unordered_map<char, std::string>{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    auto result = std::vector<std::string>{};

    backtrack("", digits, letters, result);

    return result;
}

auto print_result(std::vector<std::string> result) -> void {
    for (auto it = result.begin(); it != result.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

auto main() -> int {
    auto digits1 = "23";
    auto result1 = letterCombinations(digits1);
    print_result(result1);
}
