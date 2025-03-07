#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

auto removeStars(std::string s) -> std::string {
    std::stack<char> chars;

    for (char c : s) {
        if (c == '*') {
            chars.pop();
        } else {
            chars.push(c);
        }
    }

    std::string result = "";
    while (not chars.empty()) {
        char c = chars.top();
        chars.pop();
        result += c;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::cout << removeStars("leet**cod*e") << std::endl;   // lecoe
    std::cout << removeStars("erase*****") << std::endl;    // 
}
