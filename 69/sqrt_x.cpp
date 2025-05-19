#include <iostream>

int mySqrt(int x) {
    long long left = 1;
    long long right = x;

    // x = 38
    // return 6

    while (left <= right) {
        long long mid = (left + right) / 2;
        
        if (mid * mid <= x and x < (mid + 1) * (mid + 1)) {
            return static_cast<int>(mid);
        } else if (x < mid * mid) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return 0;
}

int main() {

}
