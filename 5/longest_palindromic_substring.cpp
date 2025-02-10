#include <string>

auto longestPalindrome(std::string s) -> std::string {
    std::string result = "";
    int max_len = 0;
    int left, right;

    for (int i = 0; i < s.size(); ++i) {
        // 1. Odd
        left = i;
        right = i;
        while (left >= 0 and right < s.size() and s[left] == s[right]) {
            int str_len = right - left + 1;
            if (str_len > max_len) {
                result = s.substr(left, str_len);
                max_len = str_len;
            }
            --left;
            ++right;
        }

        // 2. Even
        left = i;
        right = i + 1;
        while (left >= 0 and right < s.size() and s[left] == s[right]) {
            int str_len = right - left + 1;
            if (str_len > max_len) {
                result = s.substr(left, str_len);
                max_len = str_len;
            }
            --left;
            ++right;
        }
    }

    return result;
}

int main() {
    return 0;
}
