#include <string>
#include <algorithm>
#include <iostream>

auto mergeAlternately(std::string word1, std::string word2) -> std::string {
    int max_len = std::max(word1.length(), word2.length());

    // Keep adding to a string
    std::string result = "";

    for (int i = 0; i < max_len; ++i) {
        // Process word1
        if (i < word1.length()) {
            result += word1[i];
        }
        
        // Process word2
        if (i < word2.length()) {
            result += word2[i];
        }
    }

    return result;
}

int main() {
    std::cout << mergeAlternately("abc", "pqr") << std::endl;
    std::cout << mergeAlternately("ab", "pqrs") << std::endl;
    std::cout << mergeAlternately("abcd", "pq") << std::endl;
}
