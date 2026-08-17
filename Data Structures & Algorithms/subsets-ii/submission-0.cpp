class Solution {
public:

    void dfs(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int> temp){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        dfs(nums,i+1,ans,temp);
        temp.pop_back();
        while(i<nums.size()-1 && nums[i+1]==nums[i]) ++i;
        dfs(nums,i+1,ans,temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(nums,0,ans,temp);
        return ans;
    }
};
