class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> minHeap;
    int total;

    KthLargest(int k, vector<int>& nums) {
        total=k;
        for(int n:nums){
            minHeap.push(n);
            if(minHeap.size()>total){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>total){
            minHeap.pop();
        }
        return minHeap.top();
    }
};
