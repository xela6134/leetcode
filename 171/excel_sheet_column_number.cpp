#include <iostream>

int titleToNumber(std::string columnTitle) {
    // ZY = (Z - A) * 26 + (Y - A) * 1
    int curr = 0;
    for (char c : columnTitle) {
        curr = curr * 26 + (c - 'A' + 1);
    }

    return curr;
}

int main() {

}
