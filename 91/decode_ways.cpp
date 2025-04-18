#include <iostream>
#include <string>
#include <vector>

int numDecodings(std::string s) {
    // 11106
    // 226

    // 1106
    // 1 10 6

    //  dp: 54321
    // val: 2121

    //  dp: 211011 -> tricky part: start DP with dp[s.size()] = 1;
    // val: 11106

    // 21 21
    // 21 2 1
    // 2 12 1
    // 2 1 21
    // 2 1 2 1

    std::vector<int> dp(s.size() + 1, 1);
    dp[s.size()] = 1;

    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0') {
            dp[i] = 0;
        } else {
            // No need to do dp[i] = dp[i+1] + 1
            // because, for example: 1121, at 1
            // 1 + 121 isn't really 'a new case'
            // The only new thing that's added is 11 + 21
            dp[i] = dp[i+1];
            if (i + 1 < s.size() and (s[i] == '1' or (s[i] == '2' and s[i+1] < '7'))) {
                dp[i] += dp[i+2];
            }
        }
    }

    return dp[0];
}

int main() {
    
}
