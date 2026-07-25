class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int currMax=1,currMin=1;

        for(int i=0;i<nums.size();++i){
            int temp=currMax*nums[i];
            currMax=max(max(currMax*nums[i],currMin*nums[i]),nums[i]);
            currMin=min(min(temp,currMin*nums[i]),nums[i]);
            ans=max(ans,currMax);
        }
        return ans;
    }
};
