class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN, curr=0;
        for(int i=0;i<nums.size();++i){
            curr=max(curr+nums[i], nums[i]);
            maxSum=max(maxSum,curr);
        }
        return maxSum;
    }
};
