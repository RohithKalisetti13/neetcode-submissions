class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>effort(n, vector<int>(m, INT_MAX));

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;

        vector<pair<int,int>> neigh = {{-1,0},{1,0},{0,-1},{0,1}};

        pq.push({0,0,0});
        effort[0][0]=0;

        while(pq.size()>0){
            
            auto[currEffort, i, j] = pq.top();
            pq.pop();

            if(i == n-1 && j == m-1) return currEffort;

            if(currEffort>effort[i][j]) continue;

            for(auto& edge : neigh){
                int newI = i+edge.first;
                int newJ = j+edge.second;
                
                if(newI>=0 && newJ>=0 && newJ<m && newI<n){
                    
                    int newEffort = max(currEffort, abs(heights[i][j]-heights[newI][newJ]));
                    
                    if(effort[newI][newJ]>newEffort){
                        effort[newI][newJ]=newEffort;
                        pq.push({effort[newI][newJ],newI,newJ});
                    }
                }
            }
        }

        return -1;
    }
};