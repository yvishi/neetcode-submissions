class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> hash;
        for(int i=0;i<s.size();++i) hash[s[i]]=i;

        int len=0,end=0;
        vector<int> ans;
        for(int r=0;r<s.size();++r){
            len++;
            end=max(end,hash[s[r]]);
            if(r==end){
                ans.push_back(len);
                len=0;
            }
        }
        return ans;
    }
};
