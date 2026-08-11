class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();++i){
            if(hash.find(nums[i]-1)==hash.end()){
                int length=0;
                while(hash.find(nums[i]+length)!=hash.end()){
                    length++;
                }
                ans=max(ans,length);
            }
        }
        return ans;
    }
};
