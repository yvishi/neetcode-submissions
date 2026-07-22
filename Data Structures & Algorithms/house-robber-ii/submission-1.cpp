class Solution {
public:

    int dfs(vector<int>& nums, int i, vector<vector<int>>& dp, bool flag){
        if(i>=nums.size()) return 0;
        if(i==nums.size()-1 && flag) return 0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        return dp[i][flag]=max(nums[i]+dfs(nums,i+2,dp,flag),dfs(nums,i+1,dp,flag));
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<vector<int>> dp(nums.size(),vector<int>(2,-1));
        return max(dfs(nums,0,dp,1),dfs(nums,1,dp,0));
    }
};
