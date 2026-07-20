class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_set<int> path;
    unordered_set<int> visited;

    bool dfs(int c, int parent){
        if(path.count(c))
            return false;
        if(visited.count(c))
            return true;
        
        path.insert(c);
        for(int i:adj[c])
            if(i!=parent && !dfs(i,c))
                return false;
        path.erase(c);
        visited.insert(c);
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        
        for(int i=0;i<n;++i){
            adj[i]={};
        }
        for(int i=0;i<edges.size();++i){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        if(!dfs(0,-1))
            return false;
        for(int i=0;i<n;++i){
            if(visited.count(i)==0)
                return false;
        }
        return true;
    }
};
