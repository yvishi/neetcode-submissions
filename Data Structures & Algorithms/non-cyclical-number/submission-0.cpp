class Solution {
public:
    bool isHappy(int n) {
        unordered_set<long long> visit;
        while(n!=1){
            visit.insert(n);
            long long next=0;
            while(n!=0){
                int d=n%10;
                next+=(d*d);
                n/=10;
            }
            n=next;
            if(visit.count(n)) return false;
        }
        return true;
    }
};
