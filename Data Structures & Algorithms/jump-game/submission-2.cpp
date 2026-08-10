class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end=nums.size()-1;
        for(int i=end-1;i>=0;--i){
            if(nums[i]>=end-i) end=i;
        }
        return end==0;
    }
};
