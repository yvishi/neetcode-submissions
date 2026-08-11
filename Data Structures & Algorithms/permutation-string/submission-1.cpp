class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n=s2.length(), k=s1.length();
        vector<int> h1(26,0);
        for(char ch:s1){
            h1[ch-'a']++;
        }
        for(int i=0;i<=n-k;++i){
            string temp=s2.substr(i,k);
            vector<int> h2(26,0);
            for(char ch:temp){
                h2[ch-'a']++;
            }
            if(h1==h2)
                return true;
        }
        return false;
      
    }
};
