#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

int minDistance(std::string word1, std::string word2) {
    int height = word1.size() + 1;
    int width = word2.size() + 1;
    
    std::vector<std::vector<int>> dp(height, std::vector<int>(width, 0));
    
    for (int i = 0; i < width; ++i) {
        dp[0][i] = i;
    }

    for (int i = 0; i < height; ++i) {
        dp[i][0] = i;
    }

    for (int i = 1; i < height; ++i) {      // rows
        for (int j = 1; j < width; ++j) {   // columns
            // Same
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } 
            
            // Different
            else {
                dp[i][j] = std::min({
                    dp[i - 1][j - 1] + 1,   // Replace
                    dp[i - 1][j] + 1,       // Insert
                    dp[i][j - 1] + 1        // Delete
                });
            }
        }
    }

    return dp[height - 1][width - 1];
}

auto main() -> int {
    std::cout << minDistance("horse", "ros") << std::endl;
    std::cout << minDistance("intention", "execution") << std::endl;
}

/**
 * Brainstorming
 * 
 * Base cases: just increment by 1
 * Recurrence:
 * 
 * e.g. "horse" -> "ros"
 * 
 * Insert, Delete, Change, Do nothing
 * 
 * h -> r: 1 (change)
 * h -> ro: 2 (change + insert)
 * h -> ros: 3 (change + insert + insert)
 * 
 * ho -> r: 2 (change + delete)
 * ho -> ro: 1 (change)
 * ho -> ros: 2 (change + insert)
 * 
 *   . r o s
 * . 0 1 2 3
 * h 1 1 2 3
 * o 2 2 1 ?
 * 
 * h -> ros: 3 operations | ho -> ros: 4 operations
 * h -> ro : 2 operations | ho -> ros: 
 * ho -> ro: 1 operation  | ho -> ros: 2 operations
 */
