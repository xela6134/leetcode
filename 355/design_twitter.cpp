#include <vector>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <queue>

class Twitter {
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push(std::make_pair(timestamp, tweetId));
        ++timestamp;
    }
    
    auto getNewsFeed(int userId) -> std::vector<int> {
        std::priority_queue<std::pair<int, int>> combined;

        if (tweets.find(userId) != tweets.end()) {
            auto temp = tweets[userId];
            while (not temp.empty()) {
                combined.push(temp.top());
                temp.pop();
            }
        }

        for (auto followeeId : following[userId]) {
            if (tweets.find(followeeId) != tweets.end()) {
                auto temp = tweets[followeeId];
                while (not temp.empty()) {
                    combined.push(temp.top());
                    temp.pop();
                }
            }
        }

        std::vector<int> feed;
        while (not combined.empty() and feed.size() < 10) {
            feed.push_back(combined.top().second);
            combined.pop();
        }
        
        return feed;
    }
    
    // FollowerID follows FolloweeID
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    // FollowerID unfollows FolloweeID    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
private:
    // Timestamp
    int timestamp;

    // Stores all following for a user
    std::unordered_map<int, std::unordered_set<int>> following;

    // Stores tweets for a user
    // [user]: { timestamp, tweetId }
    std::unordered_map<int, std::priority_queue<std::pair<int, int>>> tweets;
};

int main() {
    return 0;
}