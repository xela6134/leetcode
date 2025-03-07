#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

auto asteroidCollision(std::vector<int>& asteroids) -> std::vector<int> {
    if (asteroids.empty()) return asteroids;

    std::stack<int> stack;
    stack.push(asteroids[0]);

    for (int i = 1; i < asteroids.size(); ++i) {
        int curr = asteroids[i];

        if (stack.empty()) {
            stack.push(curr);
            continue;
        }

        int top = stack.top();

        if ((top < 0 and curr < 0) or (top > 0 and curr > 0) or (top < 0 and curr > 0)) {
            stack.push(curr);
        } else {
            bool collided = false;
            while (not stack.empty() and stack.top() > 0 and curr < 0) {
                int absTop = std::abs(stack.top());
                int absCurr = std::abs(curr);

                if (absTop == absCurr) {
                    stack.pop();
                    collided = true;
                    break;
                } else if (absTop < absCurr) {
                    stack.pop();
                } else {
                    collided = true;
                    break;
                }
            }
            if (not collided) {
                stack.push(curr);
            }
        }
    }

    std::vector<int> result;
    while (!stack.empty()) {
        result.push_back(stack.top());
        stack.pop();
    }
    std::reverse(result.begin(), result.end());
    return result;
}

void print_result(std::vector<int>& result) {
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> asteroids1 = {5,10,-5};
    std::vector<int> asteroids2 = {8,-8};
    std::vector<int> asteroids3 = {10,2,-5};
    std::vector<int> asteroids4 = {-2, -1, 1, 2};

    auto result1 = asteroidCollision(asteroids1);
    auto result2 = asteroidCollision(asteroids2);
    auto result3 = asteroidCollision(asteroids3);
    auto result4 = asteroidCollision(asteroids4);

    print_result(result1);
    print_result(result2);
    print_result(result3);
    print_result(result4);

    return 0;
}
