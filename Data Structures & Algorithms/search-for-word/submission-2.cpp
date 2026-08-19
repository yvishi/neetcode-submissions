class Solution {
public:

    bool dfs(vector<vector<char>>& board, string word, int i, int j, int idx){
        if(idx==word.size()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[idx] || board[i][j]=='1') 
                return false;
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
       
        board[i][j]='1';
        for(int k=0;k<4;++k){
            int r=i+dir[k][0];
            int c=j+dir[k][1];
            if(dfs(board,word,r,c,idx+1)) return true;
        }
        board[i][j]=word[idx];
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(dfs(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};
