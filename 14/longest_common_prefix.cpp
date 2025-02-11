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

auto longestCommonPrefix(std::vector<std::string>& strs) -> std::string {
    if (strs.empty()) return "";

    // Start with whole string, subtract characters from the back
    std::string prefix = strs[0];

    for (int i = 1; i < strs.size(); ++i) {
        while (strs[i].find(prefix) != 0) {
            // Returning 0 means that it is found at the start

            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix == "") return "";
        }
    }

    return prefix;
}

auto main() -> int {
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::cout << longestCommonPrefix(strs) << std::endl;
    
    strs = {"dog", "racecar", "car"};
    std::cout << longestCommonPrefix(strs) << std::endl;
}