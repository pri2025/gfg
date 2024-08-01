class Solution {
public:
    void fn(vector<int> &nums, int s, int e){
        while(s<=e){
            swap(nums[s],nums[e]);
            s++; e--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        fn(nums,0,n-k-1);
        fn(nums,n-k, n-1);
        fn(nums,0,n-1);

       // vector<int> arr(n);

        // for(int i = 0; i<n; i++){
        //     arr[(i+k) % n] = nums[i];
        // }

        // for(int i = 0; i<n; i++){
        //     nums[i] = arr[i];
        // }

    }
};

//while(k--){
        //     int last = nums[n-1];
        //     for(int i = n-1; i >0; i--){
        //         nums[i] = nums[i-1];
        //     }
        //     nums[0] = last;
        // }