#include <string>

std::string longestPalindrome(std::string s) {
    if (s.empty()) return "";

    int max_len = 1;
    std::string max = s.substr(0, 1);
    int left, right;

    for (int i = 0; i < s.size(); ++i) {
        // Odd
        left = i;
        right = i;
        while (left >= 0 and right < s.size() and s[left] == s[right]) {
            if (right - left + 1 > max_len) {
                max_len = right - left + 1;
                max = s.substr(left, max_len);
            }
            --left;
            ++right;
        }

        // Even
        left = i;
        right = i + 1;
        while (left >= 0 and right < s.size() and s[left] == s[right]) {
            if (right - left + 1 > max_len) {
                max_len = right - left + 1;
                max = s.substr(left, max_len);
            }
            --left;
            ++right;
        }
    }

    return max;
}

int main() {
    return 0;
}
