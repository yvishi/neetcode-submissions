class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN, curr=0;
        for(int i=0;i<nums.size();++i){
            curr+=nums[i];
            if(nums[i]>curr) curr=nums[i];
            maxSum=max(maxSum,curr);
        }
        return maxSum;
    }
};
