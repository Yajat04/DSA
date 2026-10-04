class Twitter {
    int ts = 0;
    unordered_map <int, unordered_set <int>> followings; 
    //used set as it is easier to erase and can store single values
    unordered_map <int, vector<pair<int, int>>> tweets; 
    //{timestamp, tweetid}, as even if tid is unique may not e increasing with time globally
    //But for individual user tids will be in increasing order
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({ts++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue <tuple<int, int, int, int>> pq; 
        //{timestamp, tweetid, userid, lasttweet_idx(for user)}

        unordered_set <int> sources = followings[userId]; //just to gather all possible source
        sources.insert(userId);

        for(auto &sourceId : sources){
            if(tweets.find(sourceId) != tweets.end() && !tweets[sourceId].empty()){
                int lastidx = tweets[sourceId].size()-1; 
                //The most recent tweet for a user will be available at last index
                auto [time, tid] = tweets[sourceId][lastidx];
                pq.push({time, tid, sourceId, lastidx});
            }
        }

        vector <int> recent;
        while(!pq.empty() && recent.size() < 10){
            auto [time, tid, sourceId, lastidx] = pq.top();
            pq.pop();

            recent.push_back(tid);

            if(lastidx > 0){
                //The most recent tweet for a user will be available at last index
                auto [prevtime, prevtid] = tweets[sourceId][lastidx-1];
                pq.push({prevtime, prevtid, sourceId, lastidx-1});
            }
        }

        return recent;

        
    }
    
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */