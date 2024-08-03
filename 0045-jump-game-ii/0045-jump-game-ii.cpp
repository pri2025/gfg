class Solution {
public:
    int jump(vector<int>& nums) {
       
        int curr = 0, i=0;
        int farthest =0 ; int jump = 0;
        while(i<nums.size()-1){
            farthest = max(farthest,i+nums[i]);
            if(i == curr){
                jump++;
                curr = farthest;
            }
            if(curr >= nums.size()-1) return jump;
            i++;
        }
        return jump;
    }
};