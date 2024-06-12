class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid] == target){
                return true;
            }

            if(nums[i] == nums[mid] && nums[mid] == nums[j]){
                i++;
                j--;
                continue;
            }
            
            if(nums[i] <= nums[mid]){//left sorted
                if(nums[i]<= target && target <= nums[mid]){// in this range
                    j = mid-1;
                }
                else{
                    i = mid+1;
                }
            }
            else{//right sorted
                if(nums[mid] <= target && target <= nums[j]){
                    i = mid+1;
                }
                else{
                    j = mid-1;
                }
            }       
        }
        return false;
    }
};