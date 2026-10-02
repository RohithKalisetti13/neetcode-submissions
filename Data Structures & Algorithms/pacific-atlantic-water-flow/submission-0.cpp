class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> result;

        vector<vector<bool>> pacific(m, vector<bool>(n, false)); // visited 
        vector<vector<bool>> atlantic(m, vector<bool>(n, false)); //visited

       

        for(int j=0; j<n; j++){
            dfs(0,j,heights,heights[0][j], pacific);
            dfs(m-1,j,heights,heights[m-1][j], atlantic);
        }

        for(int i=0; i<m; i++){
            dfs(i,0,heights,heights[i][0], pacific);
            dfs(i,n-1,heights,heights[i][n-1], atlantic);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }

    void dfs(int i, int j, vector<vector<int>>& heights, int currHeight, vector<vector<bool>>&visited){
        if(i < 0 || j < 0 || i>=heights.size() || j>=heights[0].size() || heights[i][j]<currHeight || visited[i][j]) return;

        visited[i][j]=true;

        dfs(i+1,j,heights,heights[i][j], visited);
        dfs(i-1,j,heights,heights[i][j], visited);
        dfs(i,j+1,heights,heights[i][j], visited);
        dfs(i,j-1,heights,heights[i][j], visited);


    }
};
