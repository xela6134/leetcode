#include <vector>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <algorithm>

class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back(std::make_pair(userId, tweetId));
    }
    
    auto getNewsFeed(int userId) -> std::vector<int> {
        std::vector<int> newsfeed;
        int count = 0;

        for (auto it = tweets.rbegin(); it != tweets.rend(); ++it) {
            if (count >= 10) break;

            auto [user_id, tweet_id] = *it;
            if (user_id == userId || following[userId].contains(user_id)) {
                newsfeed.push_back(tweet_id);
                ++count;
            }
        }

        return newsfeed;
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
    // Stores all tweets. Stored from oldest to latest
    std::vector<std::pair<int, int>> tweets;

    // Stores all following for a user
    std::unordered_map<int, std::unordered_set<int>> following;
};