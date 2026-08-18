class Solution {
public:

    void dfs(int open, int close, int n, vector<string>& ans, string temp){
        if(close>open) return;
        if(open==n && close==n){
            ans.push_back(temp);
            return;
        }

        if(open!=n){
            dfs(open+1,close,n, ans, temp+'(');
        }
        if(close!=n){
            dfs(open, close+1,n,ans,temp+')');
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(0,0,n,ans, "");
        return ans;
    }
};
