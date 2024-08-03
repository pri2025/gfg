class Solution {
public:
     int n;
    // int fn(int indx,vector<int> &nums,vector<int> &memo){
    //     if(indx >= n) return 0;
          
    //     if(memo[indx] != -1) return memo[indx]; 
    //     int pick = nums[indx] + fn(indx+2,nums,memo);

    //     int notpick = 0 + fn(indx+1,nums,memo);

    //     return memo[indx] = max(pick,notpick);
        
    // }
    int rob(vector<int>& nums) {
        n = nums.size();
        // vector<int>memo(n,-1);
        // return fn(0,nums,memo);

        vector<int>dp(n,-1);
        dp[0] = nums[0];

        for(int i= 1;i<n;i++){
            int pick = nums[i];
            if(i > 1){
                pick += dp[i-2];
            }
            int notpick = dp[i-1];
            dp[i] = max(pick, notpick);
        }
        return dp[n-1];
    }
};