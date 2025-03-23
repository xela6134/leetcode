#include <iostream>
#include <string>
#include <unordered_map>

bool checkInclusion(std::string s1, std::string s2) {
    std::unordered_map<char, int> s1_count;
    std::unordered_map<char, int> s2_count;
    int s1_length = s1.size();
    int s2_length = s2.size();

    for (int i = 0; i < s1_length; ++i) {
        ++s1_count[s1[i]];
        ++s2_count[s2[i]];
    }

    for (int i = 0; i <= s2_length - s1_length; ++i) {
        if (s1_count == s2_count) return true;

        if (i + s1_length < s2_length) {
            if (--s2_count[s2[i]] == 0) {
                s2_count.erase(s2[i]);
            }
            ++s2_count[s2[i + s1_length]];
        }
    }

    return false;
}

int main() {
    std::cout << std::boolalpha << checkInclusion("ab", "eidbaooo") << std::endl;
    std::cout << std::boolalpha << checkInclusion("ab", "eidboaoo") << std::endl;
}
