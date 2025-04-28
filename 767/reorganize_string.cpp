#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>

std::string reorganizeString(std::string s) {
    if (s == "") return "";

    std::unordered_map<char, int> count;
    int max_count = 0;
    for (const char& c : s) {
        ++count[c];
        max_count = std::max(max_count, count[c]);
    }

    // std::cout << s.size() << ", " << max_count << std::endl;
    if ((s.size() + 1) / max_count < 2) return "";

    std::priority_queue<std::pair<int, char>> queue;
    for (const auto& [key, val] : count) {
        queue.push({val, key});
    }

    std::string result;
    while (not queue.empty()) {
        // 1. Pop the current element
        // 2. Add to string
        // 3. If not empty, pop the second element
        // 4. Add to string
        // 5. Push both back in
        auto curr1 = queue.top();
        queue.pop();

        // std::cout << curr1.first << ", " << curr1.second << std::endl;

        result += curr1.second;

        if (not queue.empty()) {
            auto curr2 = queue.top();
            queue.pop();

            result += curr2.second;
            
            if (curr2.first != 1) {
                queue.push({curr2.first - 1, curr2.second});
            }
        }

        if (curr1.first != 1) {
            queue.push({curr1.first - 1, curr1.second});
        }
    }

    return result;
}

int main() {
    std::cout << reorganizeString("aab") << std::endl;
    std::cout << reorganizeString("aaab") << std::endl;
    std::cout << reorganizeString("ddddddddddddccccccaaabb") << std::endl;
}
