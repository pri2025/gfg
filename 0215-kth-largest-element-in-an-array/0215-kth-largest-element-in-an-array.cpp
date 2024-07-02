class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() == 1){
            return nums[0];
        }
        sort(nums.begin(),nums.end());
        int s = nums[nums.size() -1];
        int cnt = 1;
        for(int i =nums.size()-2; i>=0;i--){
            if(cnt == k){
                return s;
            }
            else if(nums[i] <= s){
                s = nums[i];
                cnt++;
            }
        }
        return s;
    }
};