#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        // A queue with { currentWord, transformations }
        std::queue<std::pair<std::string, int>> queue;
        std::unordered_set<std::string> visited;
        std::unordered_set<std::string> words(wordList.begin(), wordList.end());

        queue.push({beginWord, 0});
        visited.insert(beginWord);

        while (not queue.empty()) {
            std::string curr_string = queue.front().first;
            int curr_transformation = queue.front().second;
            queue.pop();

            if (curr_string == endWord) return curr_transformation;

            for (int i = 0; i < curr_string.size(); ++i) {
                std::string new_string = curr_string;    
                for (char c = 'a'; c <= 'z'; ++c) {
                    new_string[i] = c;
                    if (words.find(new_string) != words.end() and visited.find(new_string) == visited.end()) {
                        queue.push({new_string, curr_transformation + 1});
                        visited.insert(new_string);
                    }
                }
            }
        }

        return 0;
    }
};