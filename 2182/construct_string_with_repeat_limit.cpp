#include <iostream>
#include <queue>
#include <unordered_map>

std::string repeatLimitedString(std::string s, int repeatLimit) {
    std::priority_queue<char> char_queue;
    std::unordered_map<char, int> char_count;

    for (const char& c : s) {
        if (char_count.find(c) == char_count.end()) {
            char_queue.push(c);
        }
        ++char_count[c];
    }

    std::string curr_str;
    int curr_repetitions = 0;

    while (not char_queue.empty()) {
        char curr = char_queue.top();

        
    }

    return "";
}

int main() {

}
