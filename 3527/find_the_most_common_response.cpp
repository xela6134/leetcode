#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

std::string findCommonResponse(std::vector<std::vector<std::string>>& responses) {
    std::vector<std::unordered_set<std::string>> no_duplicates;
    for (const auto& response : responses) {
        std::unordered_set<std::string> s;
        for (const auto& str : response) {
            s.insert(str);
        }
        no_duplicates.push_back(s);
    }

    int max = 0;
    std::unordered_map<std::string, int> count;
    for (const auto& set : no_duplicates) {
        for (const auto& str : set) {
            ++count[str];
            max = std::max(max, count[str]);
        }
    }

    std::vector<std::string> most_common;
    for (const auto& [key, val] : count) {
        if (val == max) most_common.push_back(key);
    }

    std::sort(most_common.begin(), most_common.end());
    return most_common[0];
}

int main() {

}
