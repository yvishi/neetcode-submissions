class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int es=((n+1)*n)/2;
        for(int i:nums){
            es-=i;
        }
        return es;
    }
};
