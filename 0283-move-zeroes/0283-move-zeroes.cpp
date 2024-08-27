class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s = nums.size();

        int i = 0, j= 0;
        for(int i =0; i<s;i++){
            if(nums[i] !=0){
                swap(nums[j],nums[i]);
                j++;
            }
        }
       /* int count = 0;
        for(int i= 0; i<s; i++){
            if(nums[i] == 0)
                count++;
        }*/
        // int k =0;
        // int j;
        // for(j =0; j<s; j++){ // 0 1 0 3 12
        //     if(nums[j] != 0){
        //         nums[k] = nums[j];
        //         k++;
        //     }
        // }
        // for( ; k< s; k++){
        //     nums[k] = 0;
        // }
    }
};