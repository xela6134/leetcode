#include <iostream>
#include <string>
#include <vector>
#include <queue>

class WordDictionary {
    class TrieNode {
    public:
        std::vector<TrieNode*> children{26, nullptr};
        bool word = false;
    };
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(std::string word) {
        TrieNode* curr = root;
        for (const char& c : word) {
            int index = c - 'a';
            if (not curr->children[index]) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }
        curr->word = true;
    }
    
    bool search(std::string word) {
        // { TrieNode, index }
        std::queue<std::pair<TrieNode*, int>> queue;
        
        if (word[0] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (root->children[i]) {
                    queue.push({root->children[i], 0});
                }
            }
        } else {
            int index = word[0] - 'a';
            if (not root->children[index]) return false;

            queue.push({root->children[index], 0});
        }

        while (not queue.empty()) {
            TrieNode* curr = queue.front().first;
            int index = queue.front().second;
            queue.pop();

            if (index == word.size() - 1) {
                if (curr->word) return true;
                else continue;
            }

            // b.d case
            if (word[index + 1] == '.') {
                for (int i = 0; i < 26; ++i) {
                    if (curr->children[i]) {
                        queue.push({curr->children[i], index + 1});
                    }
                }
            } 
            
            // bad case
            else {
                int new_index = word[index + 1] - 'a';
                if (curr->children[new_index]) {
                    queue.push({curr->children[new_index], index + 1});
                }
            }
        }

        return false;
    }
private:
    TrieNode* root;
};

int main() {

}
