class Solution {
public:

    void dfs(string u, unordered_map<string,deque<string>>& adj, vector<string>& ans){

        while(!adj[u].empty()){
            string v=adj[u].back();
            adj[u].pop_back();
            dfs(v,adj,ans);
        }
        ans.push_back(u);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,deque<string>> adj;

        for(auto ticket:tickets){
            adj[ticket[0]].push_back(ticket[1]);
        }

        for(auto& [src,dest]:adj){
            sort(dest.rbegin(),dest.rend());
        }

        vector<string> ans;
        dfs("JFK",adj,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
