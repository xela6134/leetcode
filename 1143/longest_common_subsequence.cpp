#include <iostream>
#include <string>
#include <vector>

int longestCommonSubsequence(std::string text1, std::string text2) {
    // DP
    // Definition) dp[i][j]: Length of longest common subsequence of text1[0 ~ i] & text2[0 ~ j]
    //        e.g. dp[3][2]: Length of longest common subsequence of "abc" and "ac"
    // Base Case ) All of dp[i][0] or dp[0][j] is initialised to 0 or 1
    // Recurrence) dp[i][j] = dp[i-1][j-1] + 1, or max(dp[i][j-1], dp[i-1][j])

    // DRAW IT OUT!

    //   a b c d e
    // a 1 1 1 1 1
    // b 1 2 2 2 2
    // c 1 2 3 3 3

    //   a b c f
    // d 0 0 0 0
    // a 1 1 1 1
    // f 1 1 1 2

    std::vector<std::vector<int>> dp(text2.size(), std::vector<int>(text1.size(), 0));
    if (text1[0] == text2[0]) dp[0][0] = 1;
    else dp[0][0] = 0;

    // Initialise horizontal
    for (int i = 1; i < text1.size(); ++i) {
        if (dp[0][i-1] == 1) dp[0][i] = 1;
        else {
            if (text1[i] == text2[0]) dp[0][i] = 1;
            else dp[0][i] = 0;
        }
    }

    // Initialise vertical
    for (int i = 1; i < text2.size(); ++i) {
        if (dp[i-1][0] == 1) dp[i][0] = 1;
        else {
            if (text1[0] == text2[i]) dp[i][0] = 1;
            else dp[i][0] = 0;
        }
    }

    // Whole DP, dp[i][j]
    for (int i = 1; i < text2.size(); ++i) {
        for (int j = 1; j < text1.size(); ++j) {
            if (text1[j] == text2[i]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    for (auto vec : dp) {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return dp[text2.size() - 1][text1.size() - 1];
}

int main() {
    std::cout << longestCommonSubsequence("abcde", "ace") << std::endl;
    std::cout << longestCommonSubsequence("abc", "abc") << std::endl;
    std::cout << longestCommonSubsequence("abc", "def") << std::endl;
}
