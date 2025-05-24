#include <iostream>
#include <string>
#include <vector>

std::string convertToBase7(int num) {
    // 100 -> 202
    if (num == 0) return "0";

    bool negative = false;
    if (num < 0) {
        negative = true;
        num *= -1;
    }

    // 100 = 2 * 7^2 + 0 * 7^1 + 2 * 7^0
    
    std::vector<char> digits;
    while (num > 0) {
        digits.push_back((num % 7) + '0');
        num /= 7;
    }

    std::string result = "";
    if (negative) result += '-';
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        result += *it;
    }

    return result;
}

int main() {

}
