#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
    int add = 1;
    for (int i = digits.size() - 1; i >= 0; --i) {
        bool carry = (digits[i] + add >= 10);
        digits[i] = (digits[i] + add) % 10;

        if (carry) add = 1;
        else add = 0;
    }

    if (add == 1) {
        digits.insert(digits.begin(), 1);
    }

    return digits;
}

int main() {

}
