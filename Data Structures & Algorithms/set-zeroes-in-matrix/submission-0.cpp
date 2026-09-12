class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(matrix[i][j]==0){
                    for(int c=0;c<matrix[0].size();++c){
                        if(matrix[i][c]==0) continue;
                        matrix[i][c]=-1;
                    }
                    for(int r=0;r<matrix.size();++r){
                        if(matrix[r][j]==0) continue;
                        matrix[r][j]=-1;
                    }
                }
            }
        }
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(matrix[i][j]==-1) matrix[i][j]=0;
            }
        }

    }
};
