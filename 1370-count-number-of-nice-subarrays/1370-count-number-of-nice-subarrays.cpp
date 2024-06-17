class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0;
        int odd = 0;
        map<int,int> mp; mp[0] = 1;
        int j = 0;
        while(j <nums.size()){
            if(nums[j] % 2 != 0){
                odd++;
            }
            int rem = odd-k;
            if(mp.find(rem) != mp.end()){
                count = count+mp[rem];
            }
            mp[odd]++;
            j++;
        }
        return count;
    }
};

    //for(int i =0; i<nums.size() ; i++){
        //     int temp = k;
        //     for(int j = i; j<nums.size() ; j++){
        //         if(nums[j] % 2 != 0){
        //             temp--;
        //         }
        //         if(temp == 0){
        //             count++;
        //         }
        //     }
        // }