class Solution {
public:

    string encode(vector<string>& strs) {
        string en="";
        for(string s:strs){
            en=en+s+'\0';
        }
        return en;
    }

    vector<string> decode(string s) {
        vector<string> dec;
        string temp="";
        for(char ch:s){
            if(ch=='\0'){
                dec.push_back(temp);
                temp="";
            }
            else{
                temp+=ch;
            }
        }
        return dec;
    }
};
