#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <utility>

int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
    std::unordered_set<std::string> words(wordList.begin(), wordList.end());
    std::unordered_set<std::string> visited;

    std::queue<std::pair<std::string, int>> wordQueue;
    wordQueue.push(std::make_pair(beginWord, 1));
    visited.insert(beginWord);

    while (not wordQueue.empty()) {
        // Dealing with initialising current variables
        std::string currWord = wordQueue.front().first;
        int currNum = wordQueue.front().second;
        wordQueue.pop();

        // Find all the valid words. i is the index that'll be replaced
        for (int i = 0; i < currWord.size(); ++i) {
            for (char j = 'a'; j <= 'z'; ++j) {
                std::string newWord = currWord;
                newWord[i] = j;

                if (newWord == endWord) return currNum + 1;

                // Ignore if...
                // 1. Been visited already
                // 2. Not a valid word
                if (not words.contains(newWord) or visited.contains(newWord)) continue;

                wordQueue.push(std::make_pair(newWord, currNum + 1));
                visited.insert(newWord);
                // std::cout << newWord << ", " << currNum + 1 << std::endl;
            }
        }
    }

    return 0;
}

int main() {
    std::vector<std::string> wordList = {"hot","dot","dog","lot","log","cog"};
    std::cout << ladderLength("hit", "cog", wordList) << std::endl;
}
