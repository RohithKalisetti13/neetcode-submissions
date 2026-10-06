class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        if (edges.size() != n - 1) return false;
        
        vector<bool>vis(n, false);
        vector<vector<int>> adj(n);

        for(auto& node: edges){ //building unidirected adjacency list
            int u = node[0];
            int v = node[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(isCycle(0, -1, vis, adj)){ //check fopr cycle starting from 0
            return false;
        }
        
        for(int i =0;i<n;i++){ //check if every node is connected
            if(vis[i]==false) return false;
        }

        return true;
    }

    bool isCycle(int src, int par, vector<bool>& vis, vector<vector<int>>& adj){
        vis[src]=true;
        for(int v : adj[src]){
            if(!vis[v]){
                if(isCycle(v, src, vis, adj)){
                    return true;
                }
            }
            else if(v!=par) return true;
        }
        return false;
    }
};
