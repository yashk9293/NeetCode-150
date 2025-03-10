// Question Link :- https://leetcode.com/problems/design-twitter/description/
// Design Twitter


class Twitter {
public:
    unordered_map<int, set<int>> friends;
    int time = 0;
    priority_queue<vector<int>> timeline;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        timeline.push({time, tweetId, userId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> news;
        priority_queue<vector<int>> pq = timeline;
        int n = 0;
        while(!pq.empty() && n < 10) {
            auto tweet = pq.top();
            pq.pop();
            if(tweet[2] == userId || friends[userId].count(tweet[2])) {
                news.push_back(tweet[1]);
                n++;
            }
        }
        return news;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};