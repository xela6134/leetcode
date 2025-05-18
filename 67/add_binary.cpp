#include <iostream>
#include <string>

std::string addBinary(std::string a, std::string b) {
    // 1011 -> 1101
    // 1010 -> 0101
    //         10101 -> 10101

    // a is shorter, b is longer
    if (a.size() > b.size()) std::swap(a, b);

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    int carry = 0;
    std::string result;
    for (int i = 0; i < b.size(); ++i) {
        int curr;
        if (i >= a.size()) {
            // Add b + carry
            curr = (b[i] - '0') + carry;
        } else {
            // Add a + b + carry
            curr = (a[i] - '0') + (b[i] - '0') + carry;
        }
        // Adding to string
        result += ((curr % 2) + '0');

        // Dealing with carry
        if (curr >= 2) carry = 1;
        else carry = 0;
    }

    if (carry == 1) result += '1';
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {

}
