class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0]==1 || grid[n-1][m-1]) return -1;
        
        vector<pair<int,int>> directions = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        queue<pair<int,int>>q;
        
        q.push({0,0});
    
        int distance = 1;
        while(q.size()>0){

            int levelSize = q.size();

            for(int level = 0; level < levelSize;level++){
                int i = q.front().first;
                int j = q.front().second;

                q.pop();
                if (i == n - 1 && j == m - 1) return distance;

                for(auto& it : directions){
                    int newI = i+it.first;
                    int newJ = j+it.second;

                    if(newI>=0 && newJ>=0 && newI<n && newJ<m && grid[newI][newJ]==0){
                        grid[newI][newJ]=1;
                        q.push({newI,newJ});
                    } 
                }
            }
            distance++;

        }
    return -1;
    }
};