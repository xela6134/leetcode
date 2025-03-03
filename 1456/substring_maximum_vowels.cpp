#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

bool isVowel(char c) {
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

int maxVowels(std::string s, int k) {
    int max_vowels = 0, count = 0;

    // Count vowels in the first window
    for (int i = 0; i < k; ++i) {
        if (isVowel(s[i])) ++count;
    }
    max_vowels = count;

    // Sliding window (Not O(N^2) time complexity)
    for (int i = k; i < s.size(); ++i) {
        if (isVowel(s[i])) ++count;
        if (isVowel(s[i - k])) --count;
        max_vowels = std::max(max_vowels, count);
    }

    return max_vowels;
}

int main() {
    std::cout << maxVowels("abciiidef", 3) << std::endl;
    std::cout << maxVowels("aeiou", 2) << std::endl;
    std::cout << maxVowels("leetcode", 3) << std::endl;
    std::cout << maxVowels("weallloveyou", 7) << std::endl;
}
