class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        if(hand.size()%gs!=0) return false;

        unordered_map<int,int> freq;
        for(int i:hand)
            freq[i]++;

        for(int i:hand){
            int num=i;
            while(freq[num-1]>0) num--;


            if(freq[num]>0){
                for(int j=num;j<num+gs;++j){
                    if(freq[j]>0) freq[j]--;
                    else return false;
                }
            }
        }
        return true;
    }
};
