class Solution {
public:
    stack<char> st;
    string makeGood(string s) {
        if(s.length() == 0) return "";
        for(char i : s){
            if(!st.empty() && (st.top() == i + 32 || st.top() == i - 32)){
                st.pop();
            }
            else{
                st.push(i);
            }
        }

        vector<char> res(st.size());
        for(int i = st.size() -1 ; i >= 0; i--){
            res[i] = st.top();
            st.pop();
        }

        return string(res.begin(), res.end());
        
    }
};