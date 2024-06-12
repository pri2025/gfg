class Solution {
public:

    // int bs(vector<int> &nums, int target,int i, int j){
    //    if(i > j){
    //     return -1;
    //    }
    //     int mid = (i + (j-i+1))/2;

    //     if(target == nums[mid]){
    //         return mid;
    //     }
    //     else if(target < nums[mid]){
    //         bs(nums,target, i, mid-1);
    //     }
    //     else{
    //         bs(nums,target,mid+1, j);
    //     }
    //     return -1;
    // }
    

    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        while( i <= j){
            int mid = i+(j-i)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(target < nums[mid]){
                j = mid-1;
            }
            else{
                i = mid + 1;
            }
        }
        return -1;

        // int result = bs(nums, target, i, j);
        // return result;
        

    }
};