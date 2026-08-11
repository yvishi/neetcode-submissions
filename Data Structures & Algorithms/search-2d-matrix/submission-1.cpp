class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(),col=matrix[0].size();
        int st=0,en=row*col-1;
        while(st<=en){
            int mid=(en-st)/2+st;
            int r=mid/col,c=mid%col;
            int val=matrix[r][c];
            if(val==target)
                return true;
            else if(val>target)
                en=mid-1;
            else
                st=mid+1;
        }
        return false;

    }
};
