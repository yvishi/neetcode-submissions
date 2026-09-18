class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int,vector<vector<int>>> adj;
        for(auto& it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        minHeap.push({0,k});
        while(!minHeap.empty()){
            auto [d,u]=minHeap.top();
            minHeap.pop();

            for(auto& it:adj[u]){
                int v=it[0],w=it[1];
                if(d+w < dist[v]){
                    dist[v]=d+w;
                    minHeap.push({dist[v],v});
                }
            }
        }

        int ans=INT_MIN;
        for(int i=1;i<dist.size();++i){
            if(dist[i]==INT_MAX) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};
