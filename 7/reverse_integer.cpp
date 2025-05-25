#include <iostream>
#include <climits>

int reverse(int x) {
    bool reversed = false;
    long y = static_cast<long>(x);
    if (y < 0) {
        reversed = true;
        y *= -1;
    }

    // 123 % 10 = 3
    // 12 % 10 = 2
    // 1 % 10 = 1
    
    long y_reversed = 0;
    int n = y;

    while (n > 0) {
        y_reversed = y_reversed * 10 + (n % 10);
        n /= 10;
    }

    if (reversed) y_reversed *= -1;

    if (INT_MIN <= y_reversed and y_reversed <= INT_MAX) {
        return static_cast<int>(y_reversed);
    } else {
        return 0;
    }
}

int main() {

}
