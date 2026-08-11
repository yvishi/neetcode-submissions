class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string ch:tokens){
            if(ch!="+" && ch!="-" && ch!="*" && ch!="/"){
                s.push(stoi(ch));
            }
            else{
                int num2=s.top();
                s.pop();
                int num1=s.top();
                s.pop();
                if(ch=="+") s.push(num1+num2);
                else if(ch=="-") s.push(num1-num2);
                else if(ch=="*") s.push(num1*num2);
                else{
                    if(num2==0) return -1111;
                    s.push(trunc(num1/num2));
                }
            }
        }
        return s.top();
    }
};
