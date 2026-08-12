class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        if(hand.size()%gs!=0) return false;
        unordered_map<int,int> freq;
        for(int i:hand)
            freq[i]++;

        sort(hand.begin(),hand.end());
        for(int i=0;i<hand.size();++i){
            if(freq[hand[i]]>0){
                for(int j=hand[i];j<hand[i]+gs;++j){
                    if(freq[j]>0) freq[j]--;
                    else return false;
                }
            }
        }
        return true;
    }
};
