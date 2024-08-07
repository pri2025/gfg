class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int curr = nums[0]; int cnt = 0;
        for(int i =0; i<nums.size(); i++){
            if(cnt == 0){
                curr = nums[i];
                cnt++;
            }
            else if(curr == nums[i]) cnt++;
            else cnt--;
        }

        int cnt2=0;
        for(int it : nums){
            if(it == curr) cnt2++;
        }
        if(cnt2 >= n/2) return curr;
        return -1;
      
    }
};