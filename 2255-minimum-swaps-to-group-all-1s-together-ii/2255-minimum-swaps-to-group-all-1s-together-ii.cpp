class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int it : nums){
            if(it == 1) cnt++;
        }
        if (cnt == 0 || cnt == n) return 0;
        
        int i = 0, j = 0;
        int zeros = 0;
        int mini = INT_MAX;
        for(j = 0; j <cnt;j++){
            if(nums[j] == 0)zeros++;
        }
        mini = min(mini,zeros); // intital
        while(j < n+cnt){
            if(nums[j%n] == 0)zeros++;
            if(nums[i%n] == 0)zeros--;
            
            mini = min(mini,zeros);
            j++;i++;
        }

        return mini;

    }
};