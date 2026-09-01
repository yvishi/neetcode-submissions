class Solution {
public:
    unordered_map<string, int> dp;

    int dfs(vector<int>& prices, int i, bool flag){
        if(i>=prices.size()) return 0;
        string key=to_string(i)+'-'+to_string(flag);
        if(dp.find(key)!=dp.end()) return dp[key];
        int skip=dfs(prices,i+1,flag);
        if(flag){
            return dp[key]=max(skip,dfs(prices,i+1,false)-prices[i]);
        }else{
            return dp[key]=max(skip,dfs(prices,i+2,true)+prices[i]);
        }

    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;--i){
            dp[i][0]=max(dp[i+1][0],dp[i+2][1]+prices[i]);
            dp[i][1]=max(dp[i+1][1],dp[i+1][0]-prices[i]);
        }
        return dp[0][1];



        // return dfs(prices,0, true);
    }
};
