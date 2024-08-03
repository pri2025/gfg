class Solution {
public:
     int n;
    int fn(int indx,vector<int> &nums,vector<int> &memo){
        if(indx >= n) return 0;
          
        if(memo[indx] != -1) return memo[indx]; 
        int pick = nums[indx] + fn(indx+2,nums,memo);

        int notpick = 0 + fn(indx+1,nums,memo);

        return memo[indx] = max(pick,notpick);
        
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        vector<int>memo(n,-1);
        return fn(0,nums,memo);
    }
};