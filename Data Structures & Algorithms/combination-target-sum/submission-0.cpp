class Solution {
public:

    void dfs(vector<int>& nums,int i, int target,vector<vector<int>>& ans,vector<int> temp){
        if(i==nums.size() && target!=0) return;
        if(target==0){
            ans.push_back(temp);
            return;
        }

        if(nums[i]<=target){
            temp.push_back(nums[i]);
            dfs(nums,i,target-nums[i],ans,temp);
            temp.pop_back();
        }
        dfs(nums,i+1,target,ans,temp);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(nums,0,target,ans,temp);
        return ans;
    }
};
