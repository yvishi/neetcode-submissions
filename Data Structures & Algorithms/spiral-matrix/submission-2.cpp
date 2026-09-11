class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l=0,r=matrix[0].size()-1,up=0,d=matrix.size()-1;
        vector<int> ans;
        while(l<=r && up<=d){
            for(int j=l;j<=r;++j) ans.push_back(matrix[up][j]);
            up++;
            if(up>d) break;
            for(int i=up;i<=d;++i) ans.push_back(matrix[i][r]);
            r--;
            if(l>r) break;
            for(int j=r;j>=l;--j) ans.push_back(matrix[d][j]);
            d--;
            for(int i=d;i>=up;--i) ans.push_back(matrix[i][l]);
            l++;
        }
        return ans;
    }
};
