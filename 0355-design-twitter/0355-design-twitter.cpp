class Twitter {
public:

    map<int,set<int>>friends; // followee
    map<int,vector<pair<int,int>>> tweets;
    Twitter() {
        
    }
    int time =0;
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        set<int> fr = friends[userId];
        fr.insert(userId);
        
        for(auto it : fr){
            for(auto tweet: tweets[it]){
                pq.push(tweet);
                if(pq.size()> 10){
                    pq.pop();
                }
            }
        }
        vector<int> news;
        while(!pq.empty()){
            news.push_back(pq.top().second);
            pq.pop();
        }

        reverse(news.begin(), news.end());

        return news;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
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