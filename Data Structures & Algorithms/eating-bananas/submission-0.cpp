class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int st=1,en=*max_element(piles.begin(),piles.end());
        int ans=en;
        while(st<=en){
            int mid=(en-st)/2+st;
            int tempt=0;
            for(int i:piles){
                tempt+=ceil((double)i/mid);
            }
            if(tempt<=h){
                ans=mid;
                en=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};
