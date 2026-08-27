class Solution {
public:
    unordered_map<char,string> hash={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};

    void dfs(string digits, int i, string temp, vector<string>& ans){
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
        char ch=digits[i];
        for(int j=0;j<hash[ch].size();++j){
            dfs(digits,i+1,temp+hash[ch][j],ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> ans;
        dfs(digits,0,"",ans);
        return ans;
    }
};
