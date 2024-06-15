class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i =0, j = 0, zero =0;
        int len = 0;
        while(i< nums.size()){
            if(nums[i] == 0){
                zero++;
                while(zero > k){
                    if(nums[j] == 0){
                        zero--;
                    }
                    j++;
                }
            }
            len = max(len, i-j+1);
            i++;
        }
        return len;
    }
};