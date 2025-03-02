#include <string>
#include <iostream>
#include <algorithm>

bool checkVowel(const char& c) {
    return (
        c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or
        c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U'
    );
}

auto reverseVowels(std::string s) -> std::string {
    std::string vowel_string = "";

    // Get all vowels
    for (const char& c : s) {
        if (checkVowel(c)) {
            vowel_string += c;
        }
    }

    std::reverse(vowel_string.begin(), vowel_string.end());

    // Reversing vowel process
    int vowel_index = 0;
    for (char& c : s) {
        if (checkVowel(c)) {
            c = vowel_string[vowel_index];
            ++vowel_index;
        }
    }

    return s;
}

int main() {
    std::cout << reverseVowels("IceCreAm") << std::endl;
    std::cout << reverseVowels("leetcode") << std::endl;
}
