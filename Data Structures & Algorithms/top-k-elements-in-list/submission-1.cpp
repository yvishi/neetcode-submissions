class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> freq;
        int n=nums[0],count=1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]!=n){
                freq.push_back({n,count});
                n=nums[i];
                count=1;
            }
            else{
                count++;
            }
        }
        freq.push_back({n,count});
        sort(freq.begin(),freq.end(),[](pair<int,int> a, pair<int,int> b){
            return a.second>b.second;
        });
        vector<int> ans;
        for(int i=0;i<k;++i){
            ans.push_back(freq[i].first);
        }
        return ans;
    }
};
