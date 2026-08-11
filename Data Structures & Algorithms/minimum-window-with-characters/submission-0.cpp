class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hasht;
        for(char ch:t)
            hasht[ch]++;

        int have=0,need=hasht.size(); 
        unordered_map<char,int> hashw;
        int l=0,ansi=0, len=INT_MAX;
        for(int r=0;r<s.length();++r){
            hashw[s[r]]++;
            if(hasht.count(s[r]) && hashw[s[r]]==hasht[s[r]])
                ++have;
            while(have==need){
                if(r-l+1<len){
                    ansi=l;                         
                    len=r-l+1;
                }
                hashw[s[l]]--;
                if(hasht.count(s[l]) && hashw[s[l]]<hasht[s[l]])
                    --have;
                l++;
            }
        }
        return len==INT_MAX?"":s.substr(ansi,len);
    }
};
