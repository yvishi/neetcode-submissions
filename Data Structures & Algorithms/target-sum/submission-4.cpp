class Solution {
public:

    int dfs(vector<vector<int>>& dp, vector<int>& nums, int target, int i, int total, int totalSum){
        if(i==nums.size()) return target==total;
        if(dp[i][total+totalSum]!=INT_MAX) return dp[i][total+totalSum];
        
        return dp[i][total+totalSum]=dfs(dp, nums, target, i+1, total+nums[i], totalSum)+dfs(dp, nums,target,i+1,total-nums[i], totalSum);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size(),vector<int>(2*total+1,INT_MAX));
        return dfs(dp, nums, target, 0, 0, total);
    }
};
