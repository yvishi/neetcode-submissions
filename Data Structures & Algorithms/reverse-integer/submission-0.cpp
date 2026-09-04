class Solution {
public:
    int reverse(int x) {
        int maxi=INT_MAX;
        int mini=INT_MIN;

        int ans=0;
        while(x!=0){
            int d=x%10;
            x/=10;
            if(ans>maxi/10 || ans==maxi/10 && d>=maxi%10) return 0;
            if(ans<mini/10 || ans==mini/10 && d>=mini%10) return 0;
            ans=ans*10+d;
        }
        return ans;
    }
};
