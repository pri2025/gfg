class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0 , n = nums.size();
        int  i =0, j = 0 , sum = 0;
        map<int, int> mp;
        mp[0]  =1;
        while(j < n){
            sum = sum + nums[j];
            int rem = sum - goal;
            if(mp.find(rem) != mp.end()){
                count = count + mp[rem];
            }
            mp[sum]++;
            j++;
        }
        return count;
    }
};

    //for(int i = 0; i<n ; i++){
        //     int sum = 0;
        //     for(int j = i; j<n ; j++){
        //         sum = sum + nums[j];
        //         if(sum == goal){
        //             count++;
        //         }
        //     }
        // }
        // return count;