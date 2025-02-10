#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>

// auto lengthOfLongestSubstring(std::string s) -> int {
//     int left = 0;
//     int max_length = 0;
//     auto char_set = std::unordered_set<char>{};

//     for (int right = 0; right < s.size(); right++) {
//         while (char_set.contains(s[right])) {
//             char_set.erase(s[left]);
//             left++;
//         }

//         char_set.insert(s[right]);
//         max_length = std::max(max_length, right - left + 1);
//     }

//     return max_length;
// }


// p w w k e w
// 1. 
// 2. 
// 3. 
// 4. 
// 5. 
// 6. 
// 7. 


int lengthOfLongestSubstring(std::string s) {
    int left = 0, right = 0;
    int max_len = 0;
    std::unordered_set<char> char_set;

    while (right < s.size()) {
        // std::cout << left << ", " << right << std::endl;

        if (not char_set.contains(s[right])) {
            // No duplicate encounter
            
            char_set.insert(s[right]);
            max_len = std::max(max_len, right - left + 1);
            ++right;
        } else {
            // Duplicate encounter - erase left, no counting max length for this one

            char_set.erase(s[left]);
            ++left;
        }
    }

    return max_len;
}

auto main() -> int {
    auto str = std::string("pwwkew");
    std::cout << lengthOfLongestSubstring(str) << std::endl;
}
