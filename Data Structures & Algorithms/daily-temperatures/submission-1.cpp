class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> s;
        int n=temp.size();
        vector<int> ans(n,0);
        ans[n-1]=0;
        s.push(n-1);
        for(int i=n-2;i>=0;--i){
            if(s.empty()){
                s.push(i);
            }else{
                while(!s.empty() && temp[i]>=temp[s.top()] ){
                    s.pop();
                }
                if(!s.empty()){
                    ans[i]=s.top()-i;
                }
                s.push(i);
            }
        }
        return ans;
    }
};
