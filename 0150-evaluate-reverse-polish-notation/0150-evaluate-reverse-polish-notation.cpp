class Solution {
public:
    stack<int> st;
    int evalRPN(vector<string>& s) {
        for(string i : s){
            if(i == "+" || i == "-" ||i== "*"|| i =="/"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                if(i == "+"){
                    st.push(a+b);
                }
                else if(i =="-"){
                    st.push(b-a);
                }
                else if(i== "*"){
                    st.push(a*b);
                }
                else if(i == "/"){
                    st.push(b/a);
                }
            }
            else{
                st.push(stoi(i));
            }
            
        }
        return st.top();

    }
};