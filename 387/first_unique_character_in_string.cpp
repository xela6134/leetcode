#include <iostream>
#include <string>
#include <unordered_map>

int firstUniqChar(std::string s) {
    std::unordered_map<char, int> counts;
    for (char c : s) {
        ++counts[c];
    }

    for (int i = 0; i < s.size(); ++i) {
        if (counts[s[i]] == 1) return i;
    }

    return -1;
}

int main() {

}
