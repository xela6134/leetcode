#include <iostream>
#include <vector>
#include <string>

void backtrack(std::vector<std::string>& result, std::string curr, int dots_to_insert, int index) {
    if (dots_to_insert == 0) {
        std::string last = curr.substr(index);
        if (last.size() > 3 or (last.size() > 1 and last[0] == '0')) return;

        int curr_num = std::stoi(last);
        if (curr_num >= 0 and curr_num <= 255) {
            result.push_back(curr);
        }
        return;
    }

    for (int i = 1; i <= 3; ++i) {
        if (index + i >= curr.size()) break;

        std::string segment = curr.substr(index, i);
        if (segment.size() > 1 and segment[0] == '0') continue;

        int curr_num = std::stoi(segment);
        if (curr_num >= 0 and curr_num <= 255) {
            std::string new_str = curr;
            new_str.insert(index + i, 1, '.');
            backtrack(result, new_str, dots_to_insert - 1, index + i + 1);
        }
    }
}

std::vector<std::string> restoreIpAddresses(std::string s) {
    std::vector<std::string> result;
    backtrack(result, s, 3, 0);
    return result;
}

int main() {

}
