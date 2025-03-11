#include <iostream>
#include <string>
#include <unordered_map>

bool isAnagram(std::string s, std::string t) {
    std::unordered_map<char, int> count1;
    std::unordered_map<char, int> count2;
    
    for (char& c : s) {
        ++count1[c];
    }

    for (char& c : t) {
        ++count2[c];
    }

    return count1 == count2;
}

int main() {

}
