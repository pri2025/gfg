class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> arr(n);

        for(int i = 0; i<n; i++){
            arr[(i+k) % n] = nums[i];
        }

        for(int i = 0; i<n; i++){
            nums[i] = arr[i];
        }

    }
};

//while(k--){
        //     int last = nums[n-1];
        //     for(int i = n-1; i >0; i--){
        //         nums[i] = nums[i-1];
        //     }
        //     nums[0] = last;
        // }