class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() ==1 && nums[0]== 0){
            return true;
        }
       int jump = 0;
       for(int i = 0; i<nums.size(); i++){
        if(i > jump){
            return false;
        }
        jump = max(jump, i+nums[i]);
        if(jump >= nums.size()-1){
            return true;
        }
       }
       return false;
    }
};