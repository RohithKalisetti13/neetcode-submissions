class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         vector<bool> vis(numCourses, false); //visited array
         vector<bool> recPath(numCourses, false); //recursion path

         for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(isCycle(i, vis, recPath, prerequisites)){
                    return false;
                }
            }
         }

         return true;
    }

    bool isCycle(int src, vector<bool>&vis, vector<bool>&recPath, vector<vector<int>>& prereq){
        vis[src]=true;
        recPath[src]=true;

        for(int i=0;i<prereq.size();i++){
            int u = prereq[i][1];
            int v = prereq[i][0];

            if(u==src){
                if(!vis[v]){
                    if(isCycle(v, vis, recPath, prereq))
                    return true;
                }
                else if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false;

    }
};
