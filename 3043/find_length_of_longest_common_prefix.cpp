#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class TrieNode {
public:
    TrieNode* children[10];
};

int longestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
    TrieNode* root = new TrieNode();

    for (int num1 : arr1) {
        TrieNode* cur = root;
        for (char c : std::to_string(num1)) {
            int idx = c - '0';
            if (not cur->children[idx]) cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
        }
    }

    int longest = 0;

    for (int num2 : arr2) {
        TrieNode* cur = root;
        int len = 0;

        for (char c : std::to_string(num2)) {

            int idx = c - '0';
            if (not cur->children[idx]) break;  // stop here

            cur = cur->children[idx];
            ++len;                              // we matched another digit
            longest = std::max(longest, len);
        }
    }
    return longest;
}

int main() {

}
