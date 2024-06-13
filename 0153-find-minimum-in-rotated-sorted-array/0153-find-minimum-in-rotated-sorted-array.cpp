class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int ans = INT_MAX;

        while(i <= j){
            int mid = (i+j)/2;
            if(nums[i] <= nums[j]){
                return min(ans,nums[i]);
            }
            if(nums[i] <= nums[mid]){
                ans = min(ans,nums[i]);
                i = mid+1;
            }
            else{
                ans = min(ans,nums[mid]);//right sorted
                    j = mid-1;
                }
        }
        return ans;
    }
};

//while(i<=j){
        //     int mid = (i+j)/2;
        //     if(nums[i] <= nums[mid]){
        //         mini = nums[i];
        //         i = mid+1;
        //     }
        //     if(nums[i] <= mini){
        //         mini = nums[mid+1];
        //         i++;
        //     }
        // }