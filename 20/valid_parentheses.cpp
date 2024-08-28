#include <string>
#include <iostream>
#include <stack>

auto isValid(std::string s) -> bool {
    std::stack<char> brackets;

    for (char& ch : s) {
        if (ch == '(') {
            brackets.push(ch);
        } else if (ch == ')') {
            if (not brackets.empty() and brackets.top() == '(') {
                brackets.pop();
            } else {
                return false;
            }
        } else if (ch == '{') {
            brackets.push(ch);
        } else if (ch == '}') {
            if (not brackets.empty() and brackets.top() == '{') {
                brackets.pop();
            } else {
                return false;
            }
        } else if (ch == '[') {
            brackets.push(ch);
        } else if (ch == ']') {
            if (not brackets.empty() and brackets.top() == '[') {
                brackets.pop();
            } else {
                return false;
            }
        } 
    }

    return brackets.empty();
}

auto main() -> int {
    std::cout << std::boolalpha << isValid("()") << std::endl;
    std::cout << std::boolalpha << isValid("()[]{}") << std::endl;
    std::cout << std::boolalpha << isValid("(]") << std::endl;
    std::cout << std::boolalpha << isValid("([])") << std::endl;
    std::cout << std::boolalpha << isValid("([)]") << std::endl;
    std::cout << std::boolalpha << isValid("]") << std::endl;
}
