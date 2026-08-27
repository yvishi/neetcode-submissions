class Solution {
public:

    bool possi(int row, int col, vector<string> board, int n){
        for(int i=row;i>=0;--i){
            if(board[i][col]=='Q') return false;
        }
        int i=row,j=col;
        for(;i>=0 && j>=0;--i,--j){
            if(board[i][j]=='Q') return false;
        }
        for(i=row,j=col;i>=0 && j<n;--i,++j){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }

    void dfs(vector<vector<string>>& ans, vector<string> board, int i, int n){
        if(i==n){
            ans.push_back(board);
            return;
        }

        for(int j=0;j<n;++j){
            if(possi(i,j, board, n)){
                board[i][j]='Q';
                dfs(ans,board,i+1,n);
                board[i][j]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        dfs(ans,board,0, n);
        return ans;
    }
};
