class Solution {
public:
    // int fn(int i, int j,vector<vector<int>> &memo){
    //     if(i ==0 || j == 0) return 1;
    //     if(i <0 || j <0) return 0;

    //     if(memo[i][j] != -1)return memo[i][j];
    //     int up = fn(i-1,j,memo);
    //     int left = fn(i,j-1,memo);

    //     return memo[i][j] = up+left;
    // }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> memo(m,vector<int>(n,-1));
        // return fn(m-1,n-1,memo);
        vector<vector<int>> dp(m, vector<int>(n, 0));
       // dp[0][0] = 1;
        for(int i =0;i<m;i++){
            for(int j = 0; j<n; j++){
                if( i==0 && j==0){
                    dp[i][j] = 1;
                    continue;
                }
                int up =0, left=0;
                if(j>0){
                    left = dp[i][j-1];
                }
                if(i >0){
                    up = dp[i-1][j];
                }
                dp[i][j] = left+up;
            }
        }
        return dp[m-1][n-1];
    }
};