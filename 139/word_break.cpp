#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    std::unordered_set<std::string> word_set(wordDict.begin(), wordDict.end());
    int size = s.size();
    std::vector<bool> dp(size + 1, false);
    dp[0] = true;

    for (int i = 1; i <= size; ++i) {
        for (int j = 0; j < i; ++j) {
            // Finding if string up to j can be split into 2 valid word-sets
            if (dp[j] && word_set.find(s.substr(j, i - j)) != word_set.end()) {
                dp[i] = true;
                break; // No need to continue j-loop
            }
        }
    }

    return dp[size];
}

auto main() -> int {
    std::vector<std::string> dict = {"cats","dog","sand","and","cat"};
    std::cout << std::boolalpha << wordBreak("catsandog", dict) << std::endl;

    std::vector<std::string> dict1 = {"apple", "pen"};
    std::cout << std::boolalpha << wordBreak("applepenapplepen", dict1) << std::endl;
}
