#include <vector>
#include <string>
#include <iostream>

bool is_palindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

/*
s = "aaab"
output = [["a","a","a","b"],["a","aa","b"],["aa","a","b"],["aaa","b"]]

{}
{a}                      {aa}       {aaa}
{a, a}       {a, aa}     {aa, a}    {aaa, b}
{a, a, a}    {a, aa, b}  {aa, a, b}
{a, a, a, b}
*/
void backtrack(std::vector<std::vector<std::string>>& result, std::vector<std::string>& curr, 
    const std::string& s, int index, int size) {
    
    if (index == size) {
        result.push_back(curr);
        return;
    }

    for (int i = index; i < size; ++i) {
        std::string substring = s.substr(index, i - index + 1);

        if (!is_palindrome(substring)) continue;

        curr.push_back(substring);
        backtrack(result, curr, s, i + 1, size);
        curr.pop_back();
    }
}

auto partition(std::string s) -> std::vector<std::vector<std::string>> {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> curr;
    backtrack(result, curr, s, 0, s.size());
    return result;
}

auto print_result(std::vector<std::vector<std::string>>& result) {
    for (std::vector<std::string> set : result) {
        for (std::string val : set) {
            std::cout << val << ", ";
        }
        std::cout << std::endl;
    }
}

auto main() -> int {
    std::vector<std::vector<std::string>> result = partition("aaab");
    print_result(result);
}
