class Solution {
public:

    int helper(vector<int> cost, int i, vector<int>& dp){
        if(i>cost.size()) return INT_MAX;
        else if(i==cost.size()) return 0;
        if(dp[i]!=INT_MAX) return dp[i];
        return dp[i]=min(helper(cost,i+1,dp),helper(cost,i+2,dp))+cost[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,INT_MAX);
        return min(helper(cost,0,dp),helper(cost,1,dp));

    }
};
