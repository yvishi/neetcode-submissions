class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        int len1=s.length(),len2=t.length();
        if(len1!=len2) return false;
        for(int i=0;i<len1;++i){
            freq1[s[i]-'a']++;
            freq2[t[i]-'a']++;
        }

        for(int i=0;i<26;++i){
            if(freq1[i]!=freq2[i])
                return false;
        }
        return true;
    }
};
