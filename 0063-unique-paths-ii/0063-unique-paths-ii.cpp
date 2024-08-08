class Solution {
public:
    // int fn(int i ,int j, vector<vector<int>> &memo,vector<vector<int>>& arr){
        
    //     if(i ==0 && j==0) return 1;
    //     if(i<0||j<0) return 0;
    //     if(arr[i][j] == 1)return 0;
    //     if(memo[i][j]!= -1) return memo[i][j];
    //     int up = fn(i-1,j,memo,arr);
    //     int left = fn(i,j-1,memo,arr);

    //     return memo[i][j] = up + left;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size(); int m = arr[0].size();
        if(arr[0][0] == 1) return 0;
        if(arr[n-1][m-1] == 1) return 0;
       // if(n==1 && m==1 && arr[0][0] ==1) return 0;
        //vector<vector<int>> memo(n,vector<int>(m,-1));
       // return fn(n-1,m-1,memo,arr);

       vector<vector<int>> dp(n,vector<int>(m,-1));
       dp[0][0] = 1;

       for(int i =0;i<n;i++){
        for(int j = 0; j<m;j++){
            if(i ==0 && j==0){
                dp[i][j] = 1;
                continue;
            }
            int up =0, left = 0;
            if(j >0){
                if(arr[i][j-1] != 1){
                    left = dp[i][j-1];
                }
            }

            if(i >0){
                if(arr[i-1][j] != 1){
                    up = dp[i-1][j];
                }
            }
            dp[i][j] = up + left;
        }
       }
       return dp[n-1][m-1];
    }
};