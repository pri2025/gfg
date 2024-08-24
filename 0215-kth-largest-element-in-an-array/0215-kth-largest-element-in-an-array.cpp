class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    //   priority_queue<int,vector<int> , greater<int>> minheap(nums.begin(), nums.begin() + k);

    //   for(int i = k; i< nums.size(); i++){ //from i =k because heap has k elements
    //     if(nums[i] >= minheap.top()){
    //         minheap.pop();
    //         minheap.push(nums[i]);
    //     }//changed into minheap itself
    //   }
    //   return minheap.top();
        priority_queue<int, vector<int>, greater<int>> minh;
        for(int i=0; i<nums.size();i++){
            minh.push(nums[i]);
            if(minh.size() >k){
                minh.pop();
            }
        }
        return minh.top();
    }
};

  // if(nums.size() == 1){
        //     return nums[0];
        // }
        // sort(nums.begin(),nums.end());
        // int s = nums[nums.size() -1];
        // int cnt = 1;
        // for(int i =nums.size()-2; i>=0;i--){
        //     if(cnt == k){
        //         return s;
        //     }
        //     else if(nums[i] <= s){
        //         s = nums[i];
        //         cnt++;
        //     }
        // }
        // return s;