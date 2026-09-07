class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int> ans;
        int carry=1;
        for(int i=n-1;i>=0;--i){
            if(!carry) break;
            if(digits[i]==9){
                digits[i]=0;
            }
            else{
                digits[i]++;
                carry=0;
            }
        }
        if(carry) digits.insert(digits.begin(),1);
        return digits;
    }
};
