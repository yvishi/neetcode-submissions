class Solution {
public:
    int findMin(vector<int> &nums) {
        int st=0,en=nums.size()-1;
        int ans=nums[0];
        while(st<=en){
            if(nums[en]>nums[st]){
                ans=min(ans,nums[st]);
                break;
            }
            int mid=(en-st)/2+st;
            ans=min(ans,nums[mid]);
            if(nums[mid]>=nums[st]){
                st=mid+1;
            }else{
                en=mid-1;
            }
        }
        return ans;
    }
};
