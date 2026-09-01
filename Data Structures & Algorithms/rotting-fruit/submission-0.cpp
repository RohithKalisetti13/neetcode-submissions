class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int minutes =0;
        queue<pair<int,int>>q;
        int fresh =0;

        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==2)q.push({i,j});
                else if(grid[i][j]==1)fresh++;
            }
        }
            while(!q.empty() && fresh>0){
                int size = q.size();
                for(int k =0;k<size;k++){
                    int i = q.front().first;
                    int j = q.front().second;
                    q.pop();

                    if(i-1>=0 && grid[i-1][j]==1){
                        grid[i-1][j]=2;
                        fresh--;
                        q.push({i-1,j});
                    }
                    if(i+1<grid.size() && grid[i+1][j]==1){
                        grid[i+1][j]=2;
                        fresh--;
                        q.push({i+1,j});
                    }
                    if(j-1>=0 && grid[i][j-1]==1){
                        grid[i][j-1]=2;
                        fresh--;
                        q.push({i,j-1});
                    }
                    if(j+1<grid[0].size() && grid[i][j+1]==1){
                        grid[i][j+1]=2;
                        fresh--;
                        q.push({i,j+1});
                    }
                    
                }
                minutes++;
            }
            if(fresh == 0){
                return minutes;
            }
            else{
                return -1;
            }
    }
};
