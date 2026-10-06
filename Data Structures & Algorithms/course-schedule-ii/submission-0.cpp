class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        stack<int>s;
        vector<bool>vis(numCourses, false);
        vector<bool>recPath(numCourses, false);
        vector<vector<int>>adj(numCourses);
        vector<int> res;

        for(auto& it: prerequisites){
            int course = it[0];
            int prereq = it[1];

            adj[prereq].push_back(course);
        }

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(sortOrder(i, vis, recPath, s, adj)) return {};
            }
        }

        while(s.size()>0){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }

    bool sortOrder(int src, vector<bool>&vis, vector<bool>&recPath, stack<int>&s, vector<vector<int>>& adj){
        vis[src]=true;
        recPath[src]=true;

        for(int it : adj[src]){
            if(!vis[it]){
                if(sortOrder(it, vis, recPath, s, adj)){
                    return true;
                }
            }
            else if(recPath[it]){
                return true;
            }
        }
        s.push(src);
        recPath[src]=false;
        return false;
    }
};
