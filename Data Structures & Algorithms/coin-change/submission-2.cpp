class Solution {
public:

    int dfs(int amount, vector<int>& coins, unordered_map<int,int>& dp){
        if(amount==0) return 0;
        if(dp.find(amount)!=dp.end()) return dp[amount];
        int ans=INT_MAX;
        for(int i:coins){
            if(amount-i>=0){
                int result=dfs(amount-i, coins, dp);
                if(result!=INT_MAX)
                    ans=min(ans,1+result);
            }
        }
        dp[amount]=ans;
        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int,int> dp;
        int ans=dfs(amount,coins,dp);
        return ans==INT_MAX?-1:ans;
    }
};
