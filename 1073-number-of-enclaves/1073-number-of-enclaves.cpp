class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &vis,vector<vector<int>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || vis[i][j] == 1 || grid[i][j] == 0 ){
            return;
        }

        vis[i][j] = 1;
        dfs(i+0,j+1,vis,grid);
        dfs(i+0,j-1,vis,grid);
        dfs(i+1,j+0,vis,grid);
        dfs(i-1,j+0,vis,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i = 0; i< n; i++){
            if(grid[i][0] == 1){
                dfs(i,0,vis,grid);
            }
            if(grid[i][m-1] == 1){
                dfs(i,m-1,vis,grid);
            }
        }
        for(int i =0; i<m;i++){
            if(grid[0][i] == 1){
                dfs(0,i,vis,grid);
            }
            if(grid[n-1][i] == 1){
                dfs(n-1,i,vis,grid);
            }
        }
        int cnt = 0;
        for(int i = 1; i<n-1;i++){
            for(int j= 1; j<m-1;j++){
                if(grid[i][j] == 1){
                    if(!vis[i][j]){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};