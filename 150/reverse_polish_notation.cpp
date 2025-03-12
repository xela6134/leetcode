#include <iostream>
#include <vector>
#include <string>
#include <stack>

int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> numbers;

    for (std::string& token : tokens) {
        if (token == "+") {
            int first = numbers.top();
            numbers.pop();
            int second = numbers.top();
            numbers.pop();
            numbers.push(second + first);
        } else if (token == "-") {
            int first = numbers.top();
            numbers.pop();
            int second = numbers.top();
            numbers.pop();
            numbers.push(second - first);
        } else if (token == "*") {
            int first = numbers.top();
            numbers.pop();
            int second = numbers.top();
            numbers.pop();
            numbers.push(second * first);
        } else if (token == "/") {
            int first = numbers.top();
            numbers.pop();
            int second = numbers.top();
            numbers.pop();
            numbers.push(second / first);
        } else {
            numbers.push(std::stoi(token));
        }
    }

    return numbers.top();
}

int main() {
    std::vector<std::string> tokens1 = {"2","1","+","3","*"};
    std::vector<std::string> tokens2 = {"4","13","5","/","+"};
    std::vector<std::string> tokens3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    std::cout << evalRPN(tokens1) << std::endl;
    std::cout << std::endl;
    std::cout << evalRPN(tokens2) << std::endl;
    std::cout << std::endl;
    std::cout << evalRPN(tokens3) << std::endl;
    std::cout << std::endl;
}
