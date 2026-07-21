class Solution {
public:
    unordered_set<int> visited;
    unordered_map<int,vector<int>> adj;

    void dfs(int c){
        if(visited.count(c))
            return;
        visited.insert(c);
        for(int i:adj[c]){
            dfs(i);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {        
        for(int i=0;i<n;++i){
            adj[i]={};
        }
        for(int i=0;i<edges.size();++i){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans=0;
        for(int i=0;i<n;++i){
            if(visited.count(i)==0){
                ans++;
                dfs(i);
            }
        }
        return ans;
    }
};
