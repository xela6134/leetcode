#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

// auto longestCommonPrefix(std::vector<std::string>& strs) -> std::string {
//     if (strs.empty()) return "";

//     std::string prefix = strs[0];

//     for (int i = 1; i < strs.size(); ++i) {

//         // start by comparing entire prefix and current str
//         // cut down character by character until we have a match (index 0 represents this)

//         while (strs[i].find(prefix) != 0) {
//             prefix = prefix.substr(0, prefix.length() - 1);
//             if (prefix == "") return "";
//         }
//     }

//     return prefix;
// }

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.empty()) return "";

    std::string prefix = strs[0];
    std::string curr;
    for (int i = 1; i < strs.size(); ++i) {
        curr = strs[i];

        int j = 0;
        while (j < prefix.size() and j < curr.size()) {
            if (prefix[j] == curr[j]) ++j;
            else break;
        }

        if (j == 0) return "";
        prefix = prefix.substr(0, j);
    }

    return prefix;
}

int main() {
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::cout << longestCommonPrefix(strs) << std::endl;
    
    strs = {"dog", "racecar", "car"};
    std::cout << longestCommonPrefix(strs) << std::endl;
}