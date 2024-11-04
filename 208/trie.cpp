#include <string>
#include <unordered_map>
#include <iostream>

// class TrieNode {
// public:
//     std::unordered_map<char, TrieNode*> children;
//     bool isEndOfWord = false;
// };

// class Trie {
// public:
//     Trie() {
//         root = new TrieNode();
//     }
    
//     void insert(std::string word) {
//         TrieNode* curr = root;
//         for (char& ch : word) {
//             // Character is inserted already
//             if (curr->children.find(ch) != curr->children.end()) {
//                 curr = curr->children[ch];
//             }
            
//             // Character not inserted, need to make new TrieNode
//             else {
//                 TrieNode* next = new TrieNode();
//                 curr->children[ch] = next;
//                 curr = next;
//             }
//         }
//         curr->isEndOfWord = true;
//     }
    
//     bool search(std::string word) {
//         TrieNode* curr = root;

//         for (char& ch : word) {
//             if (curr->children.find(ch) == curr->children.end()) return false;
//             curr = curr->children[ch];
//         }

//         return curr->isEndOfWord;
//     }
    
//     bool startsWith(std::string prefix) {
//         TrieNode* curr = root;

//         for (char& ch : prefix) {
//             if (curr->children.find(ch) == curr->children.end()) return false;
//             curr = curr->children[ch];
//         }

//         return true;
//     }
// private:
//     TrieNode* root;
// };

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord = false;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(std::string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int index = ch - 'a';
            if (!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }

        curr->isEndOfWord = true;
    }
    
    bool search(std::string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int index = ch - 'a';
            if (!curr->children[index]) return false;
            curr = curr->children[index];
        }

        return curr->isEndOfWord;
    }
    
    bool startsWith(std::string prefix) {
        TrieNode* curr = root;

        for (char ch : prefix) {
            int index = ch - 'a';
            if (!curr->children[index]) return false;
            curr = curr->children[index];
        }
        
        return true;
    }
private:
    TrieNode* root;
};

auto main() -> int {
    Trie trie;
    trie.insert("apple");
    std::cout << std::boolalpha << trie.search("apple") << std::endl;   // return True
    std::cout << std::boolalpha << trie.search("app") << std::endl;     // return False
    std::cout << std::boolalpha << trie.startsWith("app") << std::endl; // return True
    trie.insert("app");
    std::cout << std::boolalpha << trie.search("app") << std::endl;     // return True
}
