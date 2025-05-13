#include <iostream>
#include <string>

std::string addStrings(std::string num1, std::string num2) {        
    // 123 + 19 = 142

    // 123
    // 19

    // 321
    // 91

    // 241
    // 142

    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    int i = 0;
    int j = 0;
    int carry = 0;
    std::string result = "";
    while (i < num1.size() or j < num2.size() or carry == 1) {
        int n1 = 0;
        int n2 = 0;
        
        if (i < num1.size()) {
            n1 = num1[i++] - '0';
        } if (j < num2.size()) {
            n2 = num2[j++] - '0';
        }

        int sum = n1 + n2 + carry;

        carry = sum / 10;
        result += (sum % 10 + '0');
    }
    
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {

}
