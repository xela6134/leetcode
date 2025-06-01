#include <iostream>
#include <vector>

void reverseString(std::vector<char>& s) {
    int n = s.size();
    // 0 1 2 3 4 -> 2
    // 0 1 2 3   -> 1

    for (int i = 0; i < n / 2; ++i) {
        std::swap(s[i], s[n - 1 - i]);
    }
}

int main() {

}
