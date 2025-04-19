#include <iostream>
#include <string>
#include <stack>

int calculate(std::string s) {
    // 1. Remove all the spaces
    std::string str;
    for (const char& c : s) {
        if (c != ' ') str.push_back(c);
    }
    s = str;

    std::stack<int> nums;
    int num = 0;
    char op = '+';  // assume a '+' before the first number
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        if (not isdigit(c) or i == n - 1) {
            if (op == '+') {
                nums.push(num);
            } else if (op == '-') {
                nums.push(-num);
            } else if (op == '*') {
                int top = nums.top(); 
                nums.pop();
                nums.push(top * num);
            } else if (op == '/') {
                int top = nums.top(); 
                nums.pop();
                nums.push(top / num);
            }
            op = c;
            num = 0;
        }
    }

    int result = 0;
    while (not nums.empty()) {
        result += nums.top();
        nums.pop();
    }

    return result;
}

int main() {

}
