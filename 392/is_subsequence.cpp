#include <iostream>
#include <string>

bool isSubsequence(std::string s, std::string t) {
    // Return true is s is a subsequence of t
    int s_index = 0;

    for (int i = 0; i < t.size(); ++i) {
        if (t[i] == s[s_index]) {
            ++s_index;
        }
    }

    return s_index == s.size();
}

int main() {
    std::cout << std::boolalpha << isSubsequence("abc", "ahbgdc") << std::endl; // true
    std::cout << std::boolalpha << isSubsequence("axc", "ahbgdc") << std::endl; // false
}
