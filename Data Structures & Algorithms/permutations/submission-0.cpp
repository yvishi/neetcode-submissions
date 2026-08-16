class Solution {
public:
    unordered_set<int> check;
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int> temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(!check.count(nums[i])){
                check.insert(nums[i]);
                temp.push_back(nums[i]);
                dfs(nums, ans, temp);
                temp.pop_back();
                check.erase(nums[i]);
            }
            
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(nums, ans, temp);
        return ans;
    }
};
