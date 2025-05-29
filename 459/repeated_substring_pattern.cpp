#include <iostream>
#include <string>

bool repeatedSubstringPattern(std::string s) {
    // abababab -> bababa
    // abaaba   -> baab
    std::string doubled = s + s;
    std::string sub = doubled.substr(1, doubled.size() - 2);
    return sub.find(s) != std::string::npos;
}

int main() {

}
