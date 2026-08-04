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
        
        return dfs(prices,0, true);
    }
};
