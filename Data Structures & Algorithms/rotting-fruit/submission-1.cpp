class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;

        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }

        int time=0;
        vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            int s=q.size();
            bool flag=false;
            for(int k=0;k<s;++k){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int i=0;i<4;++i){
                    int r=row+dir[i][0];
                    int c=col+dir[i][1];
                    if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]==0 | grid[r][c]==2)
                        continue;
                    
                    grid[r][c]=2;
                    flag=true;
                    q.push({r,c});
                }
            }
            if(flag) time++;
            
        }

        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return time;
    }
};
