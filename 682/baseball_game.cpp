#include <iostream>
#include <vector>
#include <string>
#include <stack>

int calPoints(std::vector<std::string>& operations) {
    std::stack<int> nums;

    for (auto operation : operations) {
        if (operation == "+") {
            int second = nums.top();
            nums.pop();
            int first = nums.top();
            nums.pop();

            int third = first + second;
            nums.push(first);
            nums.push(second);
            nums.push(third);
        } else if (operation == "D") {
            nums.push(nums.top() * 2);
        } else if (operation == "C") {
            nums.pop();
        } else {
            nums.push(std::stoi(operation));
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
