class Twitter {
private:
    unordered_map<int,vector<pair<int,int>>> userTweet;
    unordered_map<int,unordered_set<int>> followers;
    int timer = 0;
    
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userTweet[userId].push_back({timer++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> v;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        auto feed = userTweet[userId];
        for(auto x:feed)
        {
            pq.push({x.first,x.second});
            if(pq.size() > 10)
                pq.pop();
        }
        for(auto x:followers[userId])
        {
            auto temp = userTweet[x];
            for(auto y:temp)
            {
                pq.push({y.first,y.second});
                if(pq.size() > 10)
                    pq.pop();
            }
        }
        
        while(!pq.empty())
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
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