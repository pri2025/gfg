class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r= 0, jump= 0;
        while(r < nums.size()-1){
            int farthest = 0;
            for(int i = l; i<= r; i++){
                farthest = max(farthest, i+nums[i]);
            }
            jump += 1; l =r+1; r = farthest;
        }
        return jump;
    }
};