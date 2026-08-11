class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto cust=[](vector<int>& a, vector<int>& b){
            return (a[0]*a[0]+a[1]*a[1])<(b[0]*b[0]+b[1]*b[1]);
        };

        priority_queue<vector<int>,vector<vector<int>>,decltype(cust)> maxHeap(cust);
        for(int i=0;i<points.size();++i){
            maxHeap.push(points[i]);
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        vector<vector<int>> ans;
        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return ans;
    }
};
