class Solution {
public:
    stack<char> st;
    string removeDuplicates(string s) {
        
        for(int i =0; i<s.length(); i++){
            if(!st.empty() && st.top() == s[i]){
                st.pop(); 
            }
            else{
                st.push(s[i]);
            }
        }
        vector<char> result(st.size());
            for(int i = st.size() - 1; i>=0; i--){
                result[i] = st.top();
                st.pop();
            }

        return string(result.begin(), result.end());
    //     string ans = "";
    //     while(!st.empty()){
    //         ans = ans + st.top();
    //         st.pop();
    //     }
    //    reverse(ans.begin(), ans.end());
    //     return ans;
    }
};