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
        vector<char> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
    
    // Reverse the result since we collected it in reverse order
        reverse(result.begin(), result.end());
    
    // Convert the vector to a string
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