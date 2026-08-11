class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for(char ch:str){
            if(ch=='}' || ch==')' || ch==']'){
                if(s.empty())
                    return false;
                if(ch=='}' && s.top()=='{' || ch==']' && s.top()=='[' || ch==')' && s.top()=='('){
                    s.pop();
                }else{
                    return false;
                }
            }
            else{
                s.push(ch);
            }
        }
        return s.empty();
    }
};
