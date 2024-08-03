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
        if(n ==0) return 0;
        if(n==1) return nums[0];
        // vector<int>memo(n,-1);
        // return fn(0,nums,memo);

        //vector<int>dp(n,-1);
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);

        int prev2 = nums[0], prev = max(nums[0], nums[1]);

        for(int i= 2;i<n;i++){
            // int pick = nums[i] + dp[i-2];
            // int notpick = dp[i-1];
            int pick = nums[i] + prev2;
            int notpick = prev;
            int curr = max(pick, notpick);
            prev2 = prev; prev = curr;
        }
        return prev;
    }
};