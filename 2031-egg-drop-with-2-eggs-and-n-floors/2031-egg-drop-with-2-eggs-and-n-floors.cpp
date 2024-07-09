class Solution {
public:

    int solve(int k, int n, int dp[3][1001])
    {
        if(k==1 || n==0 || n==1)
        return n;
        if(dp[k][n] != -1)
        return dp[k][n];
        int mn = INT_MAX, low, high;
        for(int k1=1; k1<=n; k1++)
        {
            if(dp[k-1][k1-1] != -1)
            low = dp[k-1][k1-1];
            else
            {
                low = solve(k-1, k1-1, dp);
                dp[k-1][k1-1] = low;
            }
            if(dp[k][n-k1] != -1)
            high = dp[k][n-k1];
            else
            {
                high = solve(k, n-k1, dp);
                dp[k][n-k1] = high;
            }
            int temp = 1 + max(low, high);
            mn = min(mn, temp);
        }
        return dp[k][n] = mn;
    }
    int twoEggDrop(int n) {
        int dp[3][1001];
        memset(dp, -1, sizeof(dp));
        return solve(2, n, dp);
    }
    // int fn(int egg, int f, vector<vector<int>> &table){
    //     if(f == 0 || f == 1) return f;
    //     if(egg == 1) return f;

    //     if(table[egg][f] != -1) return table[egg][f];

    //     int mini = INT_MAX;
    //     for(int k = 1; k<=f; k++){
    //         int low, high;
    //         //if egg breaks;
    //         if(table[egg-1][k-1] != -1){
    //             low = table[egg-1][k-1];
    //         }
    //         else{
    //             low = fn(egg-1, k-1,table);
    //             table[egg-1][k-1] = low;
    //         }

    //         //if egg breaks;
    //         if(table[egg][f-k] != -1){
    //             high = table[egg][f-k];
    //         }
    //         else{
    //             high = fn(egg,f-k, table);
    //             table[egg][f-k] = high;
    //         }

    //         //take max of worst cases;
    //         int temp = max(low,high);
    //         //choose min of max
    //         mini = min(mini,temp+1);
    //     }

    //     return table[egg][f] = mini;
    // }
    
    // int twoEggDrop(int f) {
    //     vector<vector<int>> table(3, vector<int>(f+1 , -1));
    //     //table with 3 rows( 0 1 2 egg) and f+1 columns (0,1,2...f);
    //     return fn(2,f,table);
    // }
};