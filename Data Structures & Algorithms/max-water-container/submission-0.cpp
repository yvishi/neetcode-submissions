class Solution {
public:
    int maxArea(vector<int>& height) {
        int st=0,en=height.size()-1;
        int area=0;
        while(st<en){
            area=max((en-st)*min(height[st],height[en]),area);
            if(height[st]<height[en])
                ++st;
            else --en;
        }
        return area;
    }
};
