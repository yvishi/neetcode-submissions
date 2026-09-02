class Solution {
public:

    int bin(int n){
        int count=0;
        while(n!=0){
            count+=n%2;
            n/=2;
        }
        return count;
    }

    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;++i){
            ans.push_back(bin(i));
        }
        return ans;
    }
};
