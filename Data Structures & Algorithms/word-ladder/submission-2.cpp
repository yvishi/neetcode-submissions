class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(endWord.size()==0 || find(wordList.begin(),wordList.end(),endWord)==wordList.end())
        return 0;

        unordered_map<string,vector<string>> adj;
        wordList.push_back(beginWord);
        for(string s:wordList){
            for(int i=0;i<s.size();++i){
                string pat=s.substr(0,i)+"*"+s.substr(i+1);
                adj[pat].push_back(s);
            }
        }

        unordered_set<string> visited;
        visited.insert(beginWord);
        queue<string> q;
        q.push(beginWord);
        int ans=1;
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;++i){
                string word=q.front();
                q.pop();
                if(word==endWord)
                    return ans;
                for(int j=0;j<word.size();++j){
                    string pat=word.substr(0,j)+'*'+word.substr(j+1);
                    for(string s:adj[pat]){
                        if(!visited.count(s)){
                            visited.insert(s);
                            q.push(s);
                        }
                    }
                }
            }
            ++ans;
        }
        return 0;
    }
};
