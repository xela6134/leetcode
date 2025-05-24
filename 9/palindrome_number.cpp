#include <iostream>

bool isPalindrome(int x) {
    if (x < 0 or (x % 10 == 0 and x != 0)) return false;

    // 12345 -> 54321
    
    //              n                      p
    // 12345 % 10 = 5 | (12345 - 5) / 10 = 1234
    //  1234 % 10 = 4 |  (1234 - 4) / 10 = 123
    //   123 % 10 = 3 |   (123 - 3) / 10 = 12
    //    12 % 10 = 2 |    (12 - 2) / 10 = 1
    //     1 % 10 = 1 |     (1 - 1) / 10 = 0

    long x_reversed = 0;
    int n = x;
    while (n > 0) {
        x_reversed = x_reversed * 10 + (n % 10);
        n /= 10;
    }
    x_reversed = static_cast<int>(x_reversed);
    return x == x_reversed;
}

int main() {

}
