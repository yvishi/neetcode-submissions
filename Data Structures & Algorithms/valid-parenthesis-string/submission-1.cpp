class Solution {
public:

    bool dfs(vector<vector<int>>& dp, string s, int i, int open){
        if(open<0) return false;
        if(i==s.size()) return open==0;
        if(dp[i][open]!=-1) return dp[i][open];
        if(s[i]=='(') return dp[i][open]=dfs(dp,s,i+1,open+1);
        else if(s[i]==')') return dp[i][open]=dfs(dp,s,i+1,open-1);
        else{
            return dp[i][open]=dfs(dp,s,i+1,open+1) || dfs(dp,s,i+1,open-1) || dfs(dp,s,i+1,open);
        }
    }

    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return dfs(dp,s,0,0);
    }
};
