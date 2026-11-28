class Solution {
public:
    string longestPalindrome(string s) {
        int ansL=0,ansI=0;
        for(int i=0;i<s.size();++i){
            int r=i,l=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){    
                int len=r-l+1;
                if(len>ansL) ansL=len, ansI=l;
                l--;r++;
            }
            l=i,r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                int len=r-l+1;
                if(len>ansL) ansL=len, ansI=l;
                --l;++r;
            }
        }
        return s.substr(ansI,ansL);
    }
};
