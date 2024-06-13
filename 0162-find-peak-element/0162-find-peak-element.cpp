class Solution {
public:
    int findPeakElement(vector<int>& nums) { 
        int n = nums.size();
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int i = 1;
        int j = n-2;
        while(i <= j){
            int mid = (i+j)/2;
            if(nums[mid-1] <= nums[mid] && nums[mid]>= nums[mid+1]){
                return mid;
            }

            if(nums[mid-1] < nums[mid]){
                i = mid+1;
            }
           else{
            j = mid-1;
            }
        }
    return -1;
    }
};

// for(int i =0; i<nums.size(); i++){
//             if((i == 0 || nums[i] > nums[i-1]) &&
//             (i == n-1 || nums[i] >nums[i+1])){
//                 return i;
//             }
//         }
      
//         return 0;