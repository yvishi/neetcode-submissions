class Solution {
public:

    int dfs(vector<int>& nums, int target, int i){
        if(i>=nums.size() && target!=0) return 0;
        if(target==0 && i==nums.size()) return 1;
        return dfs(nums, target+nums[i], i+1)+dfs(nums,target-nums[i],i+1);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0);
    }
};
