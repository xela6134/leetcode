#include <iostream>
#include <string>
#include <algorithm>

auto gcdOfStrings(std::string str1, std::string str2) -> std::string {
    if (str1 + str2 != str2 + str1) {
        return "";
    }

    int gcd = std::__gcd(str1.length(), str2.length());

    return str1.substr(0, gcd);
}

int main() {
    std::cout << gcdOfStrings("ABCABC", "ABC") << std::endl;
    std::cout << gcdOfStrings("ABABAB", "AB") << std::endl;
    std::cout << gcdOfStrings("LEET", "CODE") << std::endl;
}
