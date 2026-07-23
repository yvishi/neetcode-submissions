class Solution {
public:
    string longestPalindrome(string s) {
        int len=0;
        int ansi=0;

        for(int i=0;i<s.length();++i){
            int l=i,r=i;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1>len){
                    len=r-l+1;
                    ansi=l;
                }
                l--;
                r++;
            }
            l=i; r=i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1>len){
                    len=r-l+1;
                    ansi=l;
                }
                l--;
                r++;
            }
        }
        return s.substr(ansi,len);
    }
};
