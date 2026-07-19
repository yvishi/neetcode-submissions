class Solution {
public:

    void dfs(int i, int j, vector<vector<bool>>& ocean ,vector<vector<int>>& heights){
        ocean[i][j]=true;

        vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        for(int k=0;k<4;++k){
            int row=i+dir[k][0];
            int col=j+dir[k][1];

            if(row <0 || col<0 || row>=heights.size() || col>=heights[0].size() || ocean[row][col] || heights[row][col]<heights[i][j])
                continue;
            dfs(row,col,ocean,heights);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();
        vector<vector<bool>> pac(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atl(heights.size(), vector<bool>(heights[0].size(), false));

        for(int i=0;i<rows;++i){
            dfs(i,0,pac,heights);
            dfs(i,cols-1,atl,heights);
        }
        for(int i=0;i<cols;++i){
            dfs(0,i,pac,heights);
            dfs(rows-1,i,atl,heights);
        }

        vector<vector<int>> ans;
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
