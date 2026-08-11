class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, min=prices[0];
        for(int i=1;i<prices.size();++i){
            if(prices[i]<min)
                min=prices[i];
            else{
                ans=max(ans,prices[i]-min);
            }
        }
        return ans;
    }
};
