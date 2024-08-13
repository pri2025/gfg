class Solution {
public:
    int fn(int indx, int a,vector<int> &coins,vector<vector<int>> &memo){
       // if(a == 0) return 1;
        if(indx == 0){
            
            return (a % coins[indx]==0);
            
        }
        if(memo[indx][a] != -1) return memo[indx][a];
        int pick = 0;
        if(coins[indx] <= a){
            pick = fn(indx,a-coins[indx],coins,memo);
        }
        int notpick = fn(indx-1,a,coins,memo);
        return memo[indx][a] = pick+notpick;
    }
    int change(int a, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> memo(n,vector<int>(a+1,-1));
        return fn(n-1,a,coins,memo);
    }
}; 