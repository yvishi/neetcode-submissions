class Solution {
public:

    bool dfs(vector<vector<int>>& dp, vector<int>& nums, int target, int sum, int i){
        if(i==nums.size())return sum==target;
        if(sum>target) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        return dp[i][sum]=dfs(dp, nums, target,sum, i+1) || dfs(dp, nums, target, sum+nums[i], i+1);
    }

    bool canPartition(vector<int>& nums) {
        long long sum=0;
        for(int i=0;i<nums.size();++i)
            sum+=nums[i];
        if(sum%2!=0)
            return false;
        vector<vector<int>> dp(nums.size(),vector<int>(sum/2+1,-1));
        return dfs(dp, nums, sum/2, 0, 0);
    }
};
