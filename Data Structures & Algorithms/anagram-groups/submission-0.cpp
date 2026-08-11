class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;
        for(string s:strs){
            vector<int> freq(26,0);
            for(char ch:s)
                freq[ch-'a']++;
            string key=to_string(freq[0]);
            for(int i=1;i<26;++i){
                key=key+","+to_string(freq[i]);
            }
            hash[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& it:hash)
            ans.push_back(it.second);
        return ans;
    }
    
};
