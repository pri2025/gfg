class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = 0,r=0,i = 0;
        while(i < nums.size()){
            if(i > r) return false;
            l = r;
            r = max(r,i+nums[i]);
            i++;
        }
        return true;
    }
};