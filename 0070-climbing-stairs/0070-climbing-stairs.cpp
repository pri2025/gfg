class Solution {
public:
    // int fn(int indx,vector<int> &memo){
    //     if(indx<= 1) return 1;
    //     if(memo[indx] != -1) return memo[indx];
    //     memo[indx] =  fn(indx-1,memo) + fn(indx-2,memo);
    //     return memo[indx];
    // }
    int climbStairs(int n) {
        if(n <= 1)return n;
        // vector<int> memo(n+1,-1);
        // return fn(n,memo);

        //vector<int> dp(n+1);
        //dp[0] = 1; dp[1] = 1;
        int prev = 1, prev2 = 1;
        for(int i = 2; i<= n; i++){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};