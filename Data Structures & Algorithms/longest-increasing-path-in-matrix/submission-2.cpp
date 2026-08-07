class Solution {
public:

    int dfs(vector<vector<int>>& dp, vector<vector<int>>& matrix, int i, int j){
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        int ans=1;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=0;k<4;++k){
            int r=i+dir[k][0];
            int c=j+dir[k][1];
            if(r<0 || c<0 || r>=matrix.size() || c>=matrix[0].size() || matrix[r][c]<=matrix[i][j])
                continue;
            ans=max(ans,dfs(dp,matrix,r,c)+1);
        }
        return dp[i][j]=ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=1;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                ans=max(ans,dfs(dp,matrix,i,j));
            }
        }
        return ans;
    }
};
