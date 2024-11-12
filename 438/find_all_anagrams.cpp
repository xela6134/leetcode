#include <string>
#include <vector>
#include <iostream>

auto findAnagrams(std::string s, std::string p) -> std::vector<int> {
    std::vector<int> result;
    if (s.size() < p.size()) return result;

    std::vector<int> s_count(26, 0);
    std::vector<int> p_count(26, 0);

    // s is original string, p is 'ab' string
    int count = 0;
    for (char& ch : s) {
        if (count == p.size()) break;
        ++s_count[ch - 'a'];
        ++count;
    }

    for (char& ch : p) {
        ++p_count[ch - 'a'];
    }

    // Finding 'abc', s_size is 10, p_size is 3.
    // 0 1 2 3 4 5 6 7 8 9
    // c b a e b a b a c d

    for (int i = 0; i <= s.size() - p.size(); ++i) {
        // Check equality
        if (s_count == p_count) {
            result.push_back(i);
        }

        // Update s_count, but if last element, break out of for loop
        if (i + p.size() == s.size()) break;

        --s_count[s[i] - 'a'];
        ++s_count[s[i + p.size()] - 'a'];
    }

    return result;
}

void print_result(std::vector<int>& result) {
    for (int& num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

auto main() -> int {
    std::vector<int> result;
    result = findAnagrams("cbaebabacd", "abc");
    print_result(result);

    result = findAnagrams("abab", "ab");
    print_result(result);
}
