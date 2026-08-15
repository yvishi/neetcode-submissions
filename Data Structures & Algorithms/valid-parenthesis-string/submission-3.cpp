class Solution {
public:
    bool checkValidString(string s) {
        stack<int> par;
        stack<int> star;

        for(int i=0;i<s.size();++i){
            if(s[i]=='(') par.push(i);
            else if(s[i]==')'){
                if(par.empty()){
                    if(star.empty()) return false;
                    else star.pop();
                }else par.pop();
            }
            else star.push(i); 
        } 
        while(!par.empty() && !star.empty()){
            if(par.top()>star.top()) return false;
            par.pop();star.pop();
        }
        return par.empty();
    }
};
