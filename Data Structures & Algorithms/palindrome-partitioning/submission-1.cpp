class Solution {
public:

    bool isPalin(string s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }

    void dfs(string s,int j, int i, vector<string> temp, vector<vector<string>>& ans){
        if(j==s.size()){
            ans.push_back(temp);
            return;
        }
        if(i==s.size()) return; 
        
        
            if(isPalin(s,j,i)){
                temp.push_back(s.substr(j,i-j+1));
                dfs(s,i+1,i+1,temp,ans);
                cout<<temp[temp.size()-1]<<endl;
                temp.pop_back();
            }
            dfs(s,j,i+1,temp,ans);
        
        
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        dfs(s,0, 0, temp, ans);
        return ans;
    }
};
