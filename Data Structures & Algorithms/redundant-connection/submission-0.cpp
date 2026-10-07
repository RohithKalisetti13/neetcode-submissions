class Solution {
public:

    vector<int>parent;
    vector<int>rank;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n+1);
        rank.resize(n+1, 0);

        for(int i = 1;i<=n;i++){ //1-->n
            parent[i]=i;
        }

        for(auto& it : edges){
           if(unionNodes(it[0],it[1]))
           return {it[0],it[1]} ;
        }

        return {};
    }

    bool unionNodes(int u, int v){
        int parU = findF(u);
        int parV = findF(v);

        if(parU==parV) return true;

        if(rank[parU]==rank[parV]){
            parent[parV]=parU;
            rank[parU]++;
        }
        else if(rank[parU]>rank[parV]){
            parent[parV]=parU;
        }
        else{
            parent[parU]=parV;
        }

        return false;
    }

    int findF(int x){
        if(parent[x]==x) return x;
        parent[x]= findF(parent[x]);
        return parent[x];
    }
};
