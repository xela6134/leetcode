#include <iostream>
#include <vector>
#include <queue>

std::vector<int> getMiddleValue(std::vector<int>& values) {
    // smaller ones go to max_queue
    //  larger ones go to min_queue
    std::priority_queue<int> max_queue;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_queue;

    std::vector<int> result;

    // 1
    // 1 | 5
    // 1 2 | 5
    // 1 2 | 5 10
    // -99 1 2 | 5 10
    // -99 1 2 | 5 7 10
    // -99 1 2 | 5 5 7 10

    for (int num : values) {
        if (max_queue.empty() or num <= max_queue.top()) {
            max_queue.push(num);
        } else {
            min_queue.push(num);
        }

        if (min_queue.size() > max_queue.size()) {
            max_queue.push(min_queue.top());
            min_queue.pop();
        }

        result.push_back(max_queue.top());
    }

    return result;
}

int main() {
    std::vector<int> values = {1,5,2,10,-99,7,5};
    std::vector<int> result = getMiddleValue(values);
    
    // 1 5 2 10 -99 7 5
    // 1 1 2  2   2 2 5

    for (int num : result) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}
