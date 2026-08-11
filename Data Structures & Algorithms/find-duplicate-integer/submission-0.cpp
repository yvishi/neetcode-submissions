class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> check;
        for(int i:nums){
            if(check.count(i)) return i;
            check.insert(i);
        }
        return -1;
    }
};
