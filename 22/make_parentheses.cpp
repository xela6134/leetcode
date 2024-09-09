#include <vector>
#include <string>
#include <iostream>

auto backtrack(std::vector<std::string>& result, std::string curr, int open, int close, int n) -> void {
    if (curr.length() == n * 2) {
        result.push_back(curr);
    } 
    
    if (open < n) {
        backtrack(result, curr + "(", open + 1, close, n);
    }

    if (open > close) {
        backtrack(result, curr + ")", open, close + 1, n);
    }
}

auto generateParentheses(int n) -> std::vector<std::string> {
    auto result = std::vector<std::string>{};
    backtrack(result, "", 0, 0, n);
    return result;
}

auto print(std::vector<std::string> result) -> void {
    for (auto it = result.begin(); it != result.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

auto main() -> int {
    auto result1 = generateParentheses(1);
    auto result3 = generateParentheses(3);

    print(result1);
    print(result3);
}
