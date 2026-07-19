class Solution {
public:

    void dfs(vector<vector<char>>& board, int i, int j, set<pair<int,int>>& ns){
        if(ns.count({i,j})) return;
        ns.insert({i,j});

        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(int k=0;k<4;++k){
            int r=i+dir[k][0];
            int c=j+dir[k][1];

            if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]!='O')
                continue;
            dfs(board,r,c,ns);
        }
    }

    void solve(vector<vector<char>>& board) {
        set<pair<int,int>> ns;

        int rows=board.size();
        int cols=board[0].size();

        for(int i=0;i<cols;++i){
            if(board[0][i]=='O' && ns.count({0,i})==0 )
                dfs(board, 0, i, ns);
            if(board[rows-1][i]=='O' && ns.count({rows-1,i})==0)
                dfs(board, rows-1, i, ns);
        }
        for(int i=0;i<rows;++i){
            if(board[i][0]=='O' && ns.count({i,0})==0)
                dfs(board,i,0,ns);
            if(board[i][cols-1]=='O' && ns.count({i,cols-1})==0)
                dfs(board,i,cols-1,ns);
        }

        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(board[i][j]=='O' && ns.count({i,j})==0)
                    board[i][j]='X';
            }
        }
    }
};
