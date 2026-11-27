class Solution {
public:

    int helper(vector<int>& nums, vector<int>& dp,int i, bool flag){
        if(i>=nums.size()) return 0;
        else if(i==nums.size()-1 && flag) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(helper(nums,dp,i+2,flag)+nums[i],helper(nums,dp,i+1,flag)); 
    }

    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size()+1,-1);
        vector<int> dp2(nums.size()+1,-1);
        return max(helper(nums,dp1,2,true)+nums[0],helper(nums,dp2,1,false));
    }
};
