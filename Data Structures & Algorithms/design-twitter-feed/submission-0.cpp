class Twitter {
public:
    int stamp;
    unordered_map<int,vector<vector<int>>> tweets;
    unordered_map<int,set<int>> follows;
    Twitter() {
        stamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({stamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        
        auto comparator=[](vector<int>& a, vector<int>& b){
            return a[0]<b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comparator)> maxHeap(comparator);
        follows[userId].insert(userId);

        for(int followeeId:follows[userId]){
            if(tweets.count(followeeId)){
                vector<vector<int>>& t=tweets[followeeId];
                int idx=t.size()-1;
                maxHeap.push({t[idx][0],t[idx][1],followeeId, idx});
            }
        }

        vector<int> ans;
        while(!maxHeap.empty() && ans.size()<10){
            vector<int> curr=maxHeap.top();
            maxHeap.pop();
            ans.push_back(curr[1]);
            int idx=curr[3];
            if(idx>0){
                vector<int> t=tweets[curr[2]][idx-1];
                maxHeap.push({t[0],t[1],curr[2],idx-1});
            }
        }
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
