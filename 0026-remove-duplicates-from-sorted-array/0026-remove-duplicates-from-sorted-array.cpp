class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //int n = nums.size();
        if(nums.size() == 1){
            return 1;
        }
        int j =1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){

            }
            else{
                nums[j] = nums[i+1];
                j++;
            }
        }
        return j;

        // int j = 1;
        // if(n==1){
        // return 1;
        // }
        // for(int i = 1; i<n ; i++){
        //     if(nums[i] != nums[i-1]){
        //         nums[j] = nums[i];
        //         j++;
        //     }
        // }
        // return j;






        
    }
};

//int j = 1;
        // for(int i= 0; i<nums.size()-1; i++){
        //     if(nums[i] != nums[i+1]){
        //         nums[j] = nums[i+1];
        //         j++;
        //     }
           
        // }
        // return j;