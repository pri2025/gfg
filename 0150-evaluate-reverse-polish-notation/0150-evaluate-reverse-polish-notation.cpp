class Solution {
public:
int evalRPN(vector<string>& tokens) {
 int n = tokens.size();
    stack<int>st;
    for(int i=0;i<n;i++){
        if(tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/"){
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                int newNum = 0;
                if(tokens[i] == "+") newNum = num2+num1;
                else if(tokens[i] == "-") newNum = num2-num1;
                else if(tokens[i] == "*") newNum = num2*num1;
                else newNum = num2/num1;
                st.push(newNum);
        }
        else st.push(stoi(tokens[i]));
    }
    return st.top();
      }
    // stack<int> st;
    // int evalRPN(vector<string>& s) {
    //     for(int i = 0; i<s.size(); i++){
    //         if(s[i] == '+' ||  s[i] == '-' || s[i] == '*'|| s[i] ='/'){
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
    //             st.push(stoi(s[i]));
    //         }
            
    //     }
    //     return st.top();

    // }
};