class Solution {
public:

    int dfs(vector<vector<int>>& dp, int amount, vector<int>& coins, int i){
        if(i>=coins.size() || amount<0) return 0;
        if(amount==0) return 1;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int sum=0;
        if(amount>=coins[i]){
            sum+=dfs(dp, amount-coins[i], coins, i);
        }
        return dp[i][amount]=sum+dfs(dp, amount,coins,i+1);
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return dfs(dp, amount, coins,0);
    }
};
