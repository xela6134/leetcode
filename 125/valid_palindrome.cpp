#include <iostream>
#include <string>

bool isPalindrome(std::string s) {
    std::string modified = "";

    for (char c : s) {
        if ((c >= 'a' and c <= 'z') or (c >= '0' and c <= '9')) {
            modified += c;
        } else if (c >= 'A' and c <= 'Z') {
            modified += (c + 32);
        }
    }

    int left = 0;
    int right = modified.size() - 1;

    while (left < right) {
        if (modified[left] != modified[right]) return false;
        ++left;
        --right;
    }

    return true;
}

int main() {
    std::cout << std::boolalpha << isPalindrome("A man, a plan, a canal: Panama") << std::endl;
    std::cout << std::boolalpha << isPalindrome("race a car") << std::endl;
}
