#include <iostream>
#include <vector>

int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    std::vector<int> steps(n + 1);
    steps[1] = 1;
    steps[2] = 2;

    for (int i = 3; i <= n; ++i) {
        steps[i] = steps[i - 1] + steps[i - 2];
    }

    return steps[n];
}

auto main() -> int {
    std::cout << climbStairs(3) << std::endl;
    std::cout << climbStairs(4) << std::endl;
    std::cout << climbStairs(5) << std::endl;
}