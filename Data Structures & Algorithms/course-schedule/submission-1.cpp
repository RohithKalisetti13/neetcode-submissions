class Solution {
public:
    bool isCycle(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>>& adj){
        vis[src]=true;
        recPath[src]=true;

        for(auto& i: adj[src]){
                if(!vis[i]){
                    if(isCycle(i, vis, recPath, adj)){
                        return true;
                    }
                }
                else if(recPath[i]){
                    return true;
                }
        }
        recPath[src]=false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for( auto& it : prerequisites){
            int course = it[0]; 
            int prereq = it[1]; //1 is prereq for 0
            adj[prereq].push_back(course);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);

        for(int i = 0; i< numCourses;i++){
            if(!vis[i]){
                if(isCycle(i, vis, recPath, adj)){
                    return false;
                }
            }
        }
        return true;
    }
};
