class TimeMap {
public:
unordered_map<string, vector<pair<int,string>>> hash;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>> temp(hash[key].begin(),hash[key].end());
        string ans="";
        int st=0,en=temp.size()-1;
        while(st<=en){
            int mid=(en-st)/2+st;
            if(temp[mid].first<=timestamp){
                ans=temp[mid].second;
                st=mid+1;
            }else{
                en=mid-1;
            }
        }
        return ans;
    }
};
