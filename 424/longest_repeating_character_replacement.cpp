#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int characterReplacement(std::string s, int k) {
    if (s.size() == 0) return 0;

    // Initialise elements

    int max_length = 0;
    int left = 0;
    std::unordered_map<char, int> freq_count;
    int max_freq = 0;

    // AABABBA            map      max
    // A            -> A: 1       | A
    // AA           -> A: 2       | A
    // AAB          -> A: 2, B: 1 | A
    // AABA         -> A: 3, B: 1 | A
    // AABAB    (X) -> A: 3, B: 2 | A
    //   BAB        -> A: 1, B: 2 | B
    //   BABB       -> A: 1, B: 3 | B
    //   BABBA  (X) -> A: 2, B: 3 | B
    //     BBA      -> A: 1, B: 2 | B

    for (int right = 0; right < s.size(); ++right) {
        ++freq_count[s[right]];
        max_freq = std::max(max_freq, freq_count[s[right]]);

        while ((right - left + 1) - max_freq > k) {
            --freq_count[s[left]];
            ++left;
        }

        // Update curr_max_char
        max_length = std::max(max_length, right - left + 1);
    }

    return max_length;
}

int main() {
    std::string str1 = "ABAB";
    std::string str2 = "AABABBA";
    std::string str3 = "ABCDDDCBBBBBBBB";
    std::cout << characterReplacement(str1, 2) << std::endl;    // AAAA
    std::cout << characterReplacement(str2, 1) << std::endl;    // AABBBBA or AAAABBA
    std::cout << characterReplacement(str3, 2) << std::endl;
}
