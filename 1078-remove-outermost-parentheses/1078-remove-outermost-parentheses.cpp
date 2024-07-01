class Solution {
public:
stack<char> st;
    string removeOuterParentheses(string s) {
        string ans = "";
        int cnt = 0;
        for(char i : s){
            if(i == '('){
                if(cnt >0){
                    ans += i;//nested
                }
                cnt++;
            }
            else{
                cnt--;
                if(cnt >0){
                    ans += i;
                }
            }
        }
        return ans;
    }
};

//string x= "";
        //     if(i == '(') st.push(i);
        //     else{
        //         if(!st.empty()){
        //             x = st.top();
        //             st.pop();
        //             x= x+i;
        //         }
        //         if(!st.empty()){
        //             ans += x;
        //         }
        //     }
        // }