class KthLargest {
public:
    int k = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int K, vector<int>& nums): k(K) {
        //int k = K;
        int mini = INT_MAX;
       for(int i =0; i<nums.size(); i++){
            if(pq.size() < k){
                pq.push(nums[i]);
            }
            else if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
       }
    }
    
    int add(int val){
        if(pq.size() < k){
            pq.push(val);
        }
        else if(val > pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */