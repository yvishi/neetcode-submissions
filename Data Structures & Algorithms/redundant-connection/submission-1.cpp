class Solution {
public:

    int Find(vector<int>& par, int c){
        int p=par[c];
        while(p!=par[p]){
            par[p]=par[par[p]];
            p=par[p];
        }
        return p;
    }

    bool Union(vector<int>& par,vector<int>& rank, int i, int j){
        int p1=Find(par,i);
        int p2=Find(par,j);

        if(p1==p2)
            return false;
        else if(rank[p1]>rank[p2]){
            par[p2]=p1;
            rank[p1]+=rank[p2];
        }
        else{
            par[p1]=p2;
            rank[p2]+=rank[p1];
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> par(n+1);
        vector<int> rank(n+1,1);
        for(int i=0;i<=n;++i){
            par[i]=i;
        }

        for(int i=0;i<n;++i){
            if(!Union(par, rank, edges[i][0], edges[i][1]))
                return {edges[i][0],edges[i][1]};
        }
        return {};
    }
};

