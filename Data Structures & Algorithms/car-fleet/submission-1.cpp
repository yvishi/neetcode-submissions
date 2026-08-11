class Solution {
public:
    int carFleet(int target, vector<int>& positions, vector<int>& speed) {
        stack<double> s;
        vector<pair<int,int>> p;
        for(int i=0;i<positions.size();++i){
            p.push_back({target-positions[i],speed[i]});
        }
        sort(p.begin(),p.end());
        
        for(auto it:p){
            double val=(double)it.first/(double)it.second;
            if(s.empty()){
                s.push(val);
            }
            else{
                if(val>s.top()){
                    s.push(val);
                }
            }
        }
        return s.size();
    }
};
