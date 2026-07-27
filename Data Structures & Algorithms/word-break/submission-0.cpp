class Solution {
public:

    unordered_map<int,bool> dp;

    bool dfs(string s, vector<string>& wd, int i){
        if(dp.find(i)!=dp.end())
            return dp[i];
        
        for(string w:wd){
            if(i+w.length()<=s.length() && s.substr(i,w.length())==w){
                if(dfs(s,wd,i+w.length())){
                    dp[i]=true;
                    return true;
                }
            }
        }
        dp[i]=false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        dp[s.length()]=true;
        return dfs(s,wordDict, 0);
    }
};
