class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int ans = 0;
        stack<int> st;
        for(char i : s){
            if(i == '('){
                st.push(i);
                ans = max(ans, static_cast<int>(st.size()));
            }
            else if(i == ')'){
                st.pop();
            }
            // if(i == '(') cnt++;
            // else if(i== ')')cnt--;
            // ans = max(ans,cnt);
        }
        return ans;
    }
};