class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=gas.size()-1,end=0;
        int remain=gas[start]-cost[start];
        while(start>end){
            if(remain<0){
                start--;
                remain+=gas[start]-cost[start];
            }else{
                remain+=gas[end]-cost[end];
                end++;
            }
        }
        return remain>=0?start:-1;
    }
};
