class Solution {
public:
    int fn(int indx,int a, vector<int>&coins,vector<vector<int>> &memo){
       // if(a == 0) return INT_MAX-1;
        if(indx== 0){
            if(a % coins[indx] == 0){
                return a/coins[indx];
            }
            else{
                return INT_MAX-1;
            }
        }
        if(memo[indx][a] != -1)return memo[indx][a];
        int pick = INT_MAX;
        if(coins[indx] <= a){
            pick = 1 + fn(indx,a-coins[indx],coins,memo);
        }
        int notpick = fn(indx-1,a,coins,memo);
        return memo[indx][a] = min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int a) {
        if(a == 0) return 0;
        int n = coins.size();
        if(n == 1){
            if(a%coins[0] == 0){
                return a/coins[0];
            }
            else{
                return -1;
            }
        }
        vector<vector<int>> memo(n,vector<int>(a+1,-1));

        int res = fn(n-1,a,coins,memo);
        if(res == INT_MAX-1) return -1;
        else return res;
        

    }
};