class Solution {
public:

    int dfs(vector<vector<int>>& dp,vector<int>& nums, int i, int j){
        if(i==nums.size()) return 0;

        if(dp[i][j+1]!=-1) return dp[i][j+1];

        int temp=dfs(dp, nums, i+1, j);

        if(j==-1 || nums[j]<nums[i]){
            temp=max(temp,1+dfs(dp, nums, i+1, i));
        }

        return dp[i][j+1]=temp;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return dfs(dp,nums,0,-1);
    }
};
