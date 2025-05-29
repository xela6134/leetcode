#include <iostream>
#include <climits>

int reverse(int x) {
    int rev = 0;

    while (x != 0) {
        int pop = x % 10;
        x /= 10;

        // Check for overflow before pushing the digit
        if (rev > (INT_MAX / 10)) return 0;
        if (rev < (INT_MIN / 10)) return 0;

        rev = rev * 10 + pop;
    }

    return rev;
}

int main() {

}
