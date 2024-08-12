class Solution {
public:
    int fn(int indx, int sum,vector<int>& nums,int n,vector<vector<int>> &memo){
        if(indx == 0){
            if(sum == 0 && nums[0] == 0) return 2; // pick or not pick 
            if(sum == 0 || nums[0]== sum) return 1;
            return 0;
        }
        
        if(memo[indx][sum] != -1)return memo[indx][sum];

        int pick = 0;
        if(nums[indx] <= sum){
            pick = fn(indx-1,sum-nums[indx],nums,n,memo);
        }
        int notpick = fn(indx-1,sum,nums,n,memo);

        return memo[indx][sum] = pick + notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n =nums.size();
        int s =0;
        for(int i : nums){
            s += i;
        }

        if( s<abs(target) || (s+target)%2) return 0;

        int sum = (s+target)/2;
        vector<vector<int>> memo(n,vector<int>(sum+1,-1));
        return fn(n-1,sum,nums,n,memo);
    }
};