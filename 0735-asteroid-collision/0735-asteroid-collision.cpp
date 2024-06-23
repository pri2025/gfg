class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int>st;        
        for(int i: nums){
            int flag = 0;
            while(!st.empty() && i<0 && st.top() > 0){
                if(st.top() < abs(i)){
                    st.pop();
                    continue;
                }
                else if(st.top() == abs(i)){
                    st.pop();
                    flag = 1;
                }
                flag = 1;
                break;
            }
            if(flag == 0){
                st.push(i);
            }
        }
        vector<int> res(st.size());
        for(int i = st.size() -1; i >= 0; i--){
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};