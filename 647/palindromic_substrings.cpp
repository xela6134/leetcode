#include <iostream>
#include <string>
#include <vector>

int countSubstrings(std::string s) {
    // 1. Odd palindromes
    // 2. Even palindromes

    // DP
    // Problem   : dp[i][j] represents if substring i~j is a palindrome or not
    // Initial   : dp[i][i] = true, dp[i][i + 1] = true IF s[i] == s[i + 1]
    // Recurrence: if dp[i][j] == true AND s[i - 1] == s[j + 1], dp[i - 1][j + 1] = true (aligning to size)

    // e.g. dp[2][2] = true, s[1] == s[3], dp[1][3] = true

    // *****
    //  ****
    //   ***
    //    **
    //     *

    int size = s.size();
    int count = 0;

    // 1. For loop for odd size
    for (int i = 0; i < size; ++i) {
        // must be i-j >= 0, i+j < size, s[i-j] == s[i+j]
        int j = 0;
        while (i - j >= 0 and i + j < size and s[i - j] == s[i + j]) {
            ++j;
            ++count;
        }
    }

    // 2. For loop for even size
    for (int i = 0; i < size - 1; ++i) {
        int j = 0;
        while (i - j >= 0 && i + 1 + j < size && s[i - j] == s[i + 1 + j]) {
            ++j;
            ++count;
        }
    }

    return count;
}

int main() {
    std::cout << countSubstrings("abc") << std::endl;
    std::cout << countSubstrings("aaa") << std::endl;
}
