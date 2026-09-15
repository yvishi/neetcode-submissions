class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        if(num1.size()<num2.size()) swap(num1,num2);
        vector<int> mul(num1.size()+num2.size(),0);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<num2.size();++i){
            for(int j=0;j<num1.size();++j){
                int d=(num2[i]-'0')*(num1[j]-'0');
                mul[i+j]+=d;
                mul[i+j+1]+=mul[i+j]/10;
                mul[i+j]%=10;
            }
        }
        for(int i=0;i<mul.size();++i) cout<<mul[i]<<endl;
        string ans="";
        int i=mul.size()-1;
        for(;i>=0;--i){
            if(mul[i]!=0) break;
        }
        while(i>=0){
            ans=ans+char(mul[i]+'0');
            --i;
        }
        return ans;
    }
};
