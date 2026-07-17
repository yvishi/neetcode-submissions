class MedianFinder {
public:
    vector<int> data;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        data.push_back(num);
        for(int i=data.size()-2;i>=0;--i){
            if(data[i]>num)
                swap(data[i],data[i+1]);
            else{
                break;
            }
        }
    }
    
    double findMedian() {
        if(data.size()%2!=0){
            return data[data.size()/2];
        }else{
            return (double)(data[data.size()/2]+data[data.size()/2-1])/2;
        }
    }
};
