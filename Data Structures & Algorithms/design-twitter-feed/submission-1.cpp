class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>> tweet_map;
    unordered_map<int,unordered_set<int>> follow_map;
    int timestamp;
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet_map[userId].push_back({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<vector<int>> maxHeap;
        follow_map[userId].insert(userId);
        for(int followee : follow_map[userId]){
            if(!tweet_map.count(followee))
                continue;
            int last_index = tweet_map[followee].size()-1;
            auto [timestamp,tweetId] = tweet_map[followee][last_index];
            maxHeap.push({timestamp,followee,tweetId,last_index});
        }
        while(!maxHeap.empty() && feed.size() < 10){
            vector<int> latest_tweet = maxHeap.top();
            maxHeap.pop();
            int previous_index = latest_tweet[3]-1;
            int followee_id = latest_tweet[1];
            int tweet_id = latest_tweet[2];
            feed.push_back(tweet_id);
            if(previous_index >= 0){
                auto [time_stamp,tweet_id] = tweet_map[followee_id][previous_index];
                maxHeap.push({time_stamp,followee_id,tweet_id,previous_index});
            }
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        follow_map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follow_map[followerId].erase(followeeId);
    }
};
