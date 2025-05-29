#include <iostream>
#include <string>

int strStr(std::string haystack, std::string needle) {
    std::string_view h = haystack;
    std::string_view n = needle;

    int h_size = h.size();
    int n_size = n.size();

    // 012345678
    // sadbutsad

    std::string_view curr;
    for (int i = 0; i <= h_size - n_size; ++i) {
        curr = h.substr(i, n_size);
        if (curr == n) return i;
    }

    return -1;
}

int main() {

}
