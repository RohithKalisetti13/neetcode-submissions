class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int minute = 0;

        queue<pair<int,int>> q; //i,j
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty() && fresh>0){
            int levelSize = q.size();

            for(int k=0; k<levelSize; k++){
                int i = q.front().first;
                int j = q.front().second;

                q.pop();
                if(i-1 >= 0 && grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                    fresh--;
                }
                if(i+1 < grid.size() && grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                    fresh--;
                }
                if(j-1 >= 0 && grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                    fresh--;
                }
                if(j+1 < grid[0].size() && grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                    fresh--;
                }
            
            }

            minute++;
        }
        if(fresh==0) return minute;
        else return -1;
    }
};
