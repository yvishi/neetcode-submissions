class Solution {
public:

    int dfs(vector<vector<int>>& dp, string& text1, string& text2, int i, int j){
        if(i==text1.size() || j==text2.size())
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j])
            dp[i][j]=1+dfs(dp,text1,text2,i+1,j+1);
        else{
            dp[i][j]=max(dfs(dp,text1,text2,i,j+1),dfs(dp,text1,text2,i+1,j));
        }
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return dfs(dp,text1, text2, 0, 0);
    }
};
