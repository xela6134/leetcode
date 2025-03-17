#include <iostream>
#include <string>

bool isPalindrome(const std::string &s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

bool validPalindrome(std::string s) {
    int left = 0;
    int right = s.size() - 1;
    int one_ignored = false;

    // Main loop starts here
    while (left <= right) {
        std::cout << left << ": " << s[left] << ", " << right << ": " << s[right] << std::endl;

        // Characters are different
        if (s[left] != s[right]) {
            // Check both left and right
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
        --right;
        ++left;
    }

    return true;
}

int main() {
    // std::cout << std::boolalpha << validPalindrome("aba") << std::endl;
    // std::cout << std::boolalpha << validPalindrome("abca") << std::endl;
    // std::cout << std::boolalpha << validPalindrome("abc") << std::endl;
    std::cout << std::boolalpha << validPalindrome("eceec") << std::endl;
}
