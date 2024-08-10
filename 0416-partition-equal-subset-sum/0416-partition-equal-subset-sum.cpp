class Solution {
public:
    bool fn(int indx, int target,vector<int> &nums,vector<vector<int>> &memo){
        if(indx < 0)return false;
        if(target == 0) return true;
        if(memo[indx][target] != -1)return memo[indx][target];
        bool pick = false;
        if(nums[indx] <= target){
            pick = fn(indx-1,target-nums[indx],nums,memo);
        }
        bool notpick = fn(indx-1,target,nums,memo);

        return memo[indx][target] = pick || notpick;

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        if(sum % 2 != 0) return false;
        int target = sum/2;
        vector<vector<int>> memo(n,vector<int>(target+1,-1));
        
        return fn(n-1,target,nums,memo);
    }
};