class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i= 1;
        int j =nums.size()-2;
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(nums[0] != nums[1]){
            return nums[0];
        }
        if(nums[n-1] != nums[n-2]){
            return nums[n-1];
        }
        while(i <= j){
            int mid = (i+j)/2;
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
                return nums[mid];
            }
            else if(mid % 2 == 0 && nums[mid] == nums[mid+1] ||
                     mid%2 !=0 && nums[mid] == nums[mid-1]){//left side
                        i = mid + 1;
                     }
            else{
                j = mid - 1;
            }

        }
        return -1;

    }
};