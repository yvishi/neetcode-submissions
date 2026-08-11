class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st=0,en=nums.size()-1;
        while(st<=en){
            int mid=(en-st)/2+st;
            if(nums[mid]==target)
                return mid;
            if(nums[st]<=nums[mid]){
                if(target>nums[mid] || target<nums[st])
                    st=mid+1;
                else
                    en=mid-1;
            }else{
                if(target<nums[mid] || target>nums[en])
                    en=mid-1;
                else
                    st=mid+1;
            }
        }
        return -1;
    }
};
