class Solution {
public:

    bool isvalid(vector<vector<char>>& board, int row, int col){
        for(int j=0;j<9;++j){
            if(j!=col && board[row][j]==board[row][col]){
                return false;
            }
        }
        for(int i=0;i<9;++i){
            if(i!=row && board[i][col]==board[row][col]){
                return false;
            }
        }
        int sr=floor(row/3)*3,sc=floor(col/3)*3;
        for(int i=sr;i<sr+3;++i){
            for(int j=sc;j<sc+3;++j){
                if(i!=row && j!=col && board[i][j]==board[row][col])
                    return false;
            }
        }
        return true;

    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]!='.'){
                    if( !isvalid(board,i,j))
                        return false;
                }
            }
        }
        return true;
    }
};
