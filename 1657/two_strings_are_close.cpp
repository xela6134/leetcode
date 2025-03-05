#include <iostream>
#include <string>
#include <unordered_map>

bool closeStrings(std::string word1, std::string word2) {
    // 1. Swap existing characters
    // abcde -> acedb
    // There needs to be five 1s
    // Technically, (1) is a part of (2)

    // 2. Transform every occurrence of one existing character into another existing character,
    //    and do the same with the other character
    // aacabb -> bbcbaa

    // a3 b2 c1 -> a2 b3 c1
    // There needs to be one 1, one 2, and one 3

    std::unordered_map<char, int> word1_chars;
    std::unordered_map<char, int> word2_chars;
    std::unordered_map<int, int> word1_counts;
    std::unordered_map<int, int> word2_counts;

    for (const char& c : word1) {
        ++word1_chars[c];
    }

    for (const char& c : word2) {
        ++word2_chars[c];
    }

    for (const auto& [key, val] : word1_chars) {
        if (word2_chars[key] == 0) return false;
        ++word1_counts[val];
    }

    for (const auto& [key, val] : word2_chars) {
        if (word1_chars[key] == 0) return false;
        ++word2_counts[val];
    }

    for (const auto& [key, val] : word1_counts) {
        if (word2_counts[key] != val) return false;
    }

    return true;
}

int main() {
    std::cout << std::boolalpha << closeStrings("abc", "bca") << std::endl;
    std::cout << std::boolalpha << closeStrings("a", "aa") << std::endl;
    std::cout << std::boolalpha << closeStrings("cabbba", "abbccc") << std::endl;
}
