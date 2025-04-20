#include <iostream>
#include <string>
#include <list>

class Solution {
public:
    int calculate(std::string s) {
        // Step 1: Remove spaces
        std::string converted;
        for (const char& c : s) {
            if (c != ' ') converted += c;
        }

        // Step 2: Convert to list of tokens
        std::list<std::string> tokens;
        int index = 0;
        while (index < converted.size()) {
            if (converted[index] == '+' or converted[index] == '-' or 
                converted[index] == '*' or converted[index] == '/') {
                tokens.push_back(std::string(1, converted[index]));
                ++index;
            } else {
                std::string num;
                while (index < converted.size() and isdigit(converted[index])) {
                    num += converted[index];
                    ++index;
                }
                tokens.push_back(num);
            }
        }

        // Step 3: First pass for * and /
        auto it = tokens.begin();
        while (it != tokens.end()) {
            if (*it == "*" or *it == "/") {
                auto prev = std::prev(it);
                auto next = std::next(it);
                int lhs = std::stoi(*prev);
                int rhs = std::stoi(*next);
                int result = (*it == "*") ? lhs * rhs : lhs / rhs;

                // Replace prev with result, erase current and next
                *prev = std::to_string(result);
                it = tokens.erase(it); // erase operator
                it = tokens.erase(it); // erase rhs
                // now `it` is the token after lhs
            } else {
                ++it;
            }
        }

        // Step 4: Second pass for + and -
        it = tokens.begin();
        int result = std::stoi(*it);
        ++it;
        while (it != tokens.end()) {
            std::string op = *it++;
            int num = std::stoi(*it++);
            if (op == "+") result += num;
            else result -= num;
        }

        return result;
    }
};

