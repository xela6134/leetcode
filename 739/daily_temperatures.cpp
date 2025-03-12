#include <iostream>
#include <vector>
#include <stack>
#include <utility>

auto dailyTemperatures(std::vector<int>& temperatures) -> std::vector<int> {
    std::stack<std::pair<int, int>> days;

    if (temperatures.size() == 1) return {0};

    // Stack of { temperature, index }
    // 
    // 73,74,75,71,69,72,76,73
    //  1, 1, 4, 2, 1, 1, 0, 0
    // 
    // 1. Push {73, 1}
    // 2. while (days.top() < temperatures[i]) pop
    // 3. value should be (i - curr.second)

    std::vector<int> result(temperatures.size(), 0);
    days.push(std::make_pair(temperatures[0], 0));

    for (int i = 1; i < temperatures.size(); ++i) {
        // Keep popping
        while (not days.empty() and days.top().first < temperatures[i]) {
            auto curr = days.top();
            days.pop();
            result[curr.second] = i - curr.second;
        }

        days.push(std::make_pair(temperatures[i], i));
    }

    return result;
}

void print_result(const std::vector<int>& result) {
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> temperatures1 = {73,74,75,71,69,72,76,73};
    std::vector<int> temperatures2 = {30,40,50,60};
    std::vector<int> temperatures3 = {30,60,90};

    print_result(dailyTemperatures(temperatures1));
    print_result(dailyTemperatures(temperatures2));
    print_result(dailyTemperatures(temperatures3));
}
