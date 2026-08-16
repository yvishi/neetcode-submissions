class Solution {
public:

    void dfs(vector<int>& nums, int i, int target, vector<vector<int>>& ans, vector<int> temp){
        if(i==nums.size() && target!=0 || target<0) return;
        if(target==0){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        dfs(nums,i+1,target-nums[i],ans,temp);
        temp.pop_back();
        while(i<nums.size()-1 && nums[i+1]==nums[i]) ++i;
        dfs(nums,i+1,target,ans,temp);
    }

    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(c,0,target,ans,temp);
        return ans;
    }
};
