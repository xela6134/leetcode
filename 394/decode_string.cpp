#include <iostream>
#include <string>
#include <stack>

std::string decodeString(std::string s) {
    std::stack<int> count_stack;
    std::stack<std::string> str_stack;

    std::string result;
    int num = 0;

    for (char c : s) {
        // Keep adding numbers
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } 
        // Start of string
        else if (c == '[') {
            count_stack.push(num);
            str_stack.push(result);
            num = 0;
            result = "";
        } 
        // End of string
        else if (c == ']') {
            int repeat = count_stack.top(); 
            count_stack.pop();
            
            std::string prev = str_stack.top(); 
            str_stack.pop();
            
            for (int i = 0; i < repeat; ++i) {
                prev += result;
            }

            result = prev;
        } 
        // Plain chars
        else {
            result += c;
        }
    }

    return result;
}

int main() {

}
