class Solution {
public:
    unordered_map<int,bool> dp;
    bool dfs(vector<int>& nums, int i){
        if(i==nums.size()-1) return true;
        if(dp.find(i)!=dp.end()) return dp[i];
        for(int j=0;j<nums[i];++j){
            if(i+nums[i]-j<nums.size() && dfs(nums,i+nums[i]-j)) 
                return dp[i]=true;
        }
        return dp[i]=false;
    }

    bool canJump(vector<int>& nums) {
        return dfs(nums, 0);
    }
};
