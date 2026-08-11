class Solution {
    public:
        int characterReplacement(string s, int k) {
            unordered_map<char,int>hash;
            int ans=0,l=0,max_len=0;
            for(int i=0;i<s.length();++i){
                hash[s[i]]++;
                max_len=max(max_len,hash[s[i]]);
                while(i-l+1-max_len>k){
                    hash[s[l]]--;
                    l++;
                }
                ans=max(ans,i-l+1);
            }
            return ans;
        }
};