class CountSquares {
public:

    unordered_map<int,int> hash;
    vector<vector<int>> points;
    CountSquares() {
        
    }
    int getKey(int x,int y){
        return x+y*10000;
    }

    void add(vector<int> point) {
        hash[getKey(point[0],point[1])]++;
        points.push_back(point);
    }
    
    int count(vector<int> pt) {
        int ans=0;
        for(vector<int>& pts:points){
            if(abs(pts[0]-pt[0])!=abs(pts[1]-pt[1]) || pts[0]==pt[0]   || pts[1]==pt[1]) continue;
            ans+=hash[getKey(pts[0],pt[1])]*hash[getKey(pt[0],pts[1])];
        }
        return ans;
    }
};
