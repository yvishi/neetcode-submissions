class Solution {
public:

    int dfs(vector<vector<int>>& dp, vector<int>& nums, int l, int r){
        if(l>r) return 0;
        
        if(dp[l][r]!=-1) return dp[l][r];

        dp[l][r]=0;

        for(int i=l;i<=r;++i){
            int sum=nums[l-1]*nums[i]*nums[r+1];
            sum+=dfs(dp,nums,l,i-1)+dfs(dp,nums,i+1,r);
            dp[l][r]=max(dp[l][r],sum);
        }
        return dp[l][r];
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return dfs(dp,nums,1,nums.size()-2);
    }
};
