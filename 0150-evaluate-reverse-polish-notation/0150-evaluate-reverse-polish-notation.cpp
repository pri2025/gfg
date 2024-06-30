class Solution {
public:

   int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string str : tokens) {
            if(str == "+" || str == "-" || str == "*" || str == "/") {
                int val1 = stk.top();
                stk.pop();
                int val2 = stk.top();
                stk.pop();
                int result;
                if(str == "+") {
                    result = val2 + val1;
                }
                else if(str == "-") {
                    result = val2 - val1;
                }
                else if(str == "*") {
                    result = val2 * val1;
                }
                else if(str == "/") {
                    result = val2 / val1;
                }
                stk.push(result);
            }
            else {
                stk.push(stoi(str));
            }
        }
        return stk.top();
    }
    // stack<int> st;
    // int evalRPN(vector<string>& s) {
    //     for(string i : s){
    //         if(i == '+' || i == '-' ||i== '*'|| i ='/'){
    //             int a = st.top(); st.pop();
    //             int b = st.top(); st.pop();
    //             if(s[i] == '+'){
    //                 st.push(a+b);
    //             }
    //             else if(s[i] =='-'){
    //                 st.push(b-a);
    //             }
    //             else if(s[i] == '*'){
    //                 st.push(a*b);
    //             }
    //             else{
    //                 st.push(a/b);
    //             }
    //         }
    //         else{
    //             st.push(stoi(i));
    //         }
            
    //     }
    //     return st.top();

    // }
};