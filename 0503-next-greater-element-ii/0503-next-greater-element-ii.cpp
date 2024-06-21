class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> res(n,-1);
        for(int i = 2*n-1; i>= 0; i--){
            while(!st.empty() && st.top() <= nums[i % n]){
                st.pop();
            }
            if( i < n){
                if(!st.empty()){
                    res[i] = st.top();
                }
                else{
                    res[i] = -1;
                }
            }
            st.push(nums[i % n]);
        }
        return res;
    }
};

//if linear array
    //for(int i = n-1; i>=0; i--){
        //     while(!st.empty() && st.top() < nums[i] ){
        //         st.pop();
        //     }
        //     if(!st.empty()){
        //         res[i] = st.top();
        //     }
        //     st.push(nums[i]);
        // }
        // return res;