class Solution {
public:
    unordered_map<int,int> dp;
    int dfs(vector<int>& nums, int i){
        if(i>=nums.size()-1) return 0;
        if(nums[i]==0) return dp[i]=INT_MAX-2;
        if(dp.count(i)) return dp[i]; 
        dp[i]=INT_MAX;       
        for(int j=nums[i];j>0;--j){
            if(i+j<nums.size()){
                dp[i]=min(dp[i],1+dfs(nums, i+j));
            }
        }
        return dp[i];
    }

    int jump(vector<int>& nums) {
        return dfs(nums, 0);
    }
};
