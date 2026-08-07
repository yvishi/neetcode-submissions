class Solution {
public:

    int dfs(vector<vector<int>>& dp, string s, string t, int i, string temp){
        if(i>=s.size() || temp.size()==t.size()) return temp==t;
        if(temp!=t.substr(0,temp.size())) return 0;
        if(dp[i][temp.size()]!=-1) return dp[i][temp.size()];
        return dp[i][temp.size()]=dfs(dp,s,t,i+1,temp+s[i])+dfs(dp,s,t,i+1,temp);
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size()+1,-1));
        return dfs(dp,s,t,0,"");
    }
};
