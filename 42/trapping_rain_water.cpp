#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int trap(std::vector<int> height) {
    if (height.empty()) {
        return 0;
    }

    int l = 0;
    int r = height.size() - 1;
    int leftMax = height[l];
    int rightMax = height[r];
    int res = 0;

    while (l < r) {
        if (leftMax < rightMax) {
            l++;
            leftMax = std::max(leftMax, height[l]);
            res += leftMax - height[l];
        } else {
            r--;
            rightMax = std::max(rightMax, height[r]);
            res += rightMax - height[r];
        }
    }
    return res;
}

int trap1(std::vector<int> height) {
    // input     0 1 0 2 1 0 1 3 2 1 2 1
    // maxLeft   0 0 1 1 2 2 2 2 3 3 3 3
    // maxRight  3 3 3 3 3 3 3 2 2 2 1 0
    // min(L, R) 0 0 1 1 2 2 2 2 2 2 1 0
    // output    0 0 1 0 1 2 1 0 0 1 0 0

    int n = height.size();
    if (n == 0) return 0;

    std::vector<int> maxLeft(n);
    std::vector<int> maxRight(n);
    maxLeft[0] = height[0];
    for (int i = 1; i < n; ++i) {
        maxLeft[i] = std::max(maxLeft[i - 1], height[i]);
    }

    maxRight[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        maxRight[i] = std::max(maxRight[i + 1], height[i]);
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        int curr_min = std::min(maxLeft[i], maxRight[i]);
        if (curr_min > height[i]) {
            result += curr_min - height[i];
        }
    }

    return result;
}

int main() {
    std::cout << trap({0,1,0,2,1,0,1,3,2,1,2,1}) << std::endl;
}
