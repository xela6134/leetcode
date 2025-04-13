#include <iostream>
#include <stack>
#include <string>

bool checkValidString(std::string s) {
    std::stack<int> left, star;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            left.push(i);
        } else if (s[i] == '*') {
            star.push(i);
        } else {
            if (left.empty() and star.empty()) return false;
            
            if (not left.empty()) {
                left.pop();
            } else {
                star.pop();
            }
        }
    }
    
    while (not left.empty() and not star.empty()) {
        if (left.top() > star.top()) return false;
        left.pop();
        star.pop();
    }

    return left.empty();
}

int main() {

}
