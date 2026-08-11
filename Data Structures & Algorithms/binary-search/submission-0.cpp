class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st=0,en=nums.size()-1;
        while(st<=en){
            int mid=(en-st)/2+st;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                --en;
            else
                ++st;
        }
        return -1;
    }
};
