class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxHeap;
        queue<pair<int,int>> q;
        int time=0;
        vector<int> hash(26,0);
        for(char ch:tasks){
            hash[ch-'A']++;
        }
        for(int i:hash){
            if(i>0)
                maxHeap.push(i);
        }
        while(!maxHeap.empty() || !q.empty()){
            ++time;
            if(!maxHeap.empty()){
                if(maxHeap.top()>1)
                    q.push({maxHeap.top()-1, time+n});
                maxHeap.pop();
            }else{
                time=q.front().second;
            }

            if(!q.empty() && q.front().second==time){
                maxHeap.push(q.front().first);
                q.pop();
            }
            
        }
        return time;
    }
};
