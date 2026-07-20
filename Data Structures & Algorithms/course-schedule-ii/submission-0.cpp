class Solution {
public:

    bool dfs(int c, unordered_map<int,vector<int>>& adj, vector<int>& ans, unordered_set<int>& visited, unordered_set<int>& path){
        if(visited.count(c))
            return true;
        if(path.count(c))
            return false;
        path.insert(c);
        for(int i:adj[c]){
            if(!dfs(i, adj, ans, visited, path))
                return false;
        }
        visited.insert(c);
        path.erase(c);
        adj[c].clear();
        ans.push_back(c);
        return true;
    }

    vector<int> findOrder(int n, vector<vector<int>>& pr) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;++i){
            adj[i]={};
        }
        for(int i=0;i<pr.size();++i){
            adj[pr[i][0]].push_back(pr[i][1]);
        }

        vector<int> ans;
        unordered_set<int> visited;
        unordered_set<int> path;

        for(int i=0;i<n;++i){
            if(!dfs(i, adj, ans, visited, path))
                return {};
        }
        return ans;
    }
};
