class Solution {
public:
    vector<int>parent;
    vector<int> rank;

    int countComponents(int n, vector<vector<int>>& edges) {
       // if(n==1 || edges.empty()) return n;

        parent.resize(n);
        rank.resize(n, 0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int count = n;
        
        for(auto& it : edges){
            int a = it[0];
            int b = it[1];

            if(unionNodes(a,b)){
                count--;
            }
        }

        return count;

    }

    int findParent(int x){
        if(parent[x]==x) return x;
        parent[x] = findParent(parent[x]);
        return parent[x];
    }

    bool unionNodes(int n1, int n2){
        int parentA = findParent(n1);
        int parentB = findParent(n2);

        if(parentA==parentB) return false;

        if(rank[parentA]==rank[parentB]){
            parent[parentB] = parentA;
            rank[parentA]++;
        }
        else if(rank[parentA]>rank[parentB]){
            parent[parentB] = parentA;
        }
        else{
            parent[parentA] = parentB;
        }

        return true;
    }
};
