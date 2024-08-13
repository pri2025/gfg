class Solution {
public:
    // int fn(int indx, int a,vector<int> &coins,vector<vector<int>> &memo){
    //    // if(a == 0) return 1;
    //     if(indx == 0){
            
    //         return (a % coins[indx]==0);
            
    //     }
    //     if(memo[indx][a] != -1) return memo[indx][a];
    //     int pick = 0;
    //     if(coins[indx] <= a){
    //         pick = fn(indx,a-coins[indx],coins,memo);
    //     }
    //     int notpick = fn(indx-1,a,coins,memo);
    //     return memo[indx][a] = pick+notpick;
    // }
    int change(int a, vector<int>& coins) {
        int n = coins.size();
       // vector<vector<int>> memo(n,vector<int>(a+1,-1));
        //return fn(n-1,a,coins,memo);
        vector<vector<int>> dp(n+1,vector<int>(a+1,-1));
        for(int i=0; i<a+1;i++){
            dp[0][i] = 0;
        }
        for(int i = 0; i<n+1;i++){
            dp[i][0] = 1;
        }

        for(int i =1; i<n+1; i++){
            for(int j = 1; j<a+1;j++){
                int pick = 0;
                if(coins[i-1] <= j){
                    pick = dp[i][j-coins[i-1]];
                }
                int notpick = dp[i-1][j];

                dp[i][j] = pick+notpick;
            }
        }
        return dp[n][a];

    }
}; 