#include <iostream>
#include <string>

int lengthOfLastWord(std::string s) {
    std::reverse(s.begin(), s.end());

    int index = 0;
    while (index < s.size()) {
        // Ignore spaces
        if (s[index] == ' ') {
            ++index;
            continue;
        }

        int curr_len = 0;
        while (index < s.size() and s[index] != ' ') {
            ++index;
            ++curr_len;
        }

        return curr_len;
    }

    return -1;
}

int main() {

}
