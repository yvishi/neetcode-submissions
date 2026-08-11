class MedianFinder {
public:
    vector<int> data;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        data.push_back(num);
    }
    
    double findMedian() {
        sort(data.begin(),data.end());
        if(data.size()%2!=0){
            return data[data.size()/2];
        }else{
            return (double)(data[data.size()/2]+data[data.size()/2-1])/2;
        }
    }
};
