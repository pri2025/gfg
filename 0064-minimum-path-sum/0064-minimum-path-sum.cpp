class Solution {
public:
    // int fn(int i, int j,vector<vector<int>>& grid,vector<vector<int>> &memo){
    //     if(i <0 || j <0) return INT_MAX;//do not return 0
    //     if(i ==0 && j ==0) return grid[i][j];
    //     if(memo[i][j]!= -1) return memo[i][j];
    //     // int sum += grid[i][j];
    //     int up = INT_MAX; int left = INT_MAX;
    //    if(i > 0){
    //         up = grid[i][j] + fn(i-1,j,grid,memo);
    //    }
    //     if(j >0){
    //         left = grid[i][j] + fn(i,j-1,grid,memo);
    //     }
    //     memo[i][j] = min(up,left);
    //     return memo[i][j];
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> memo(n,vector<int>(m,-1));
        // return fn(n-1,m-1,grid,memo);
        vector<vector<int>> dp(n,vector<int>(m,-1));
        //dp[0][0] = grid[0][0];
        for(int i =0; i <n;i++){
            for(int j= 0; j<m;j++){
                if(i ==0 && j ==0){
                    dp[i][j] = grid[0][0];
                    continue;
                }
                int up = INT_MAX, left = INT_MAX;
                if(i >0){
                    up = dp[i-1][j];
                }
                if(j >0){
                    left = dp[i][j-1];
                }
                dp[i][j] = grid[i][j] + min(up,left);
            }
           
        }
        return dp[n-1][m-1];
    }
};