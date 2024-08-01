class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        int i = 2 ;// pos to insert
        int j = 2; //curr 
        while(j <nums.size()){
            if(nums[j] == nums[i-2]) j++;
            else{
                nums[i] =nums[j];
                i++;j++;
            }
        }
        return i;
    }
};