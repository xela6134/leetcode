#include <iostream>
#include <string>
#include <vector>

std::string convert(std::string s, int numRows) {
    if (numRows == 1 or numRows >= s.size()) {
        return s;
    }

    std::vector<std::string> rows(numRows);
    int currRow = 0;
    bool goingDown = false;

    for (char c : s) {
        rows[currRow] += c;
        if (currRow == 0 or currRow == numRows - 1) {
            goingDown = !goingDown;
        }
        currRow += goingDown ? 1 : -1;
    }

    std::string result;
    for (std::string& row : rows) {
        result += row;
    }

    return result;
}

int main() {

}
