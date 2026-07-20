class Solution {
public:
    unordered_map<int,vector<int>> hash;
    unordered_set<int> visited;
    
    bool dfs(int c){
        if(visited.count(c))
            return false;
        if(hash[c].empty())
            return true;
        
        visited.insert(c);
        for(auto it:hash[c]){
            if(!dfs(it))
                return false;
        }
        visited.erase(c);
        hash[c].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& pr) {
        for(int i=0;i<numCourses;++i){
            hash[i]={};
        }    
        for(int i=0;i<pr.size();++i){
            hash[pr[i][0]].push_back(pr[i][1]);
        }

        for(int i=0;i<numCourses;++i){
            if(!dfs(i))
                return false;
        }
        return true;
    }
};
