class Solution {
public:

    int dfs(vector<vector<int>>& dp, string w1, string w2, int i, int j){
        if(i>=w1.size() || j>=w2.size()) return max(w1.size()-i,w2.size()-j);
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i]==w2[j])
            return dp[i][j]=dfs(dp, w1,w2,i+1,j+1);
        return dp[i][j]=1+min({dfs(dp, w1,w2,i+1,j), dfs(dp, w1,w2,i,j+1), dfs(dp, w1,w2,i+1,j+1)});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return dfs(dp, word1, word2, 0, 0);
    }
};
