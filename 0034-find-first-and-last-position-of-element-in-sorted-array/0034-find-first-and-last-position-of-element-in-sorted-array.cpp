class Solution {
public:
    int firstOcc(vector<int>& nums, int target){
        int first = -1;
        int i = 0;
        int j = nums.size() - 1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid] == target){
                first = mid;
                j = mid-1;
            }
            else if(nums[mid]< target){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        return first;
    }
    int lastOcc(vector<int> &nums, int target){
        int last = -1;
        int i = 0;
        int j = nums.size() - 1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid] == target){
                last = mid;
                i = mid+1;
            }
            else if(nums[mid] < target){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first = firstOcc(nums,target);
        int last = lastOcc(nums,target);
        return{first,last};

    }
};

//int first = -1;
        // int last= -1;
        // for(int i =0; i<nums.size(); i++){
        //     if(nums[i] == target){
        //         if(first == -1){
        //             first = i;
        //         }
        //         last = i;
        //     }
            
        // }
        // ans.push_back(first);
        // ans.push_back(last);
        // return ans;