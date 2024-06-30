class Solution {
public:
    //stack<char> st;
    int minAddToMakeValid(string s) {
        int l = 0, r = 0;
        for(char i : s){
            if(i == ')'){
                if(l == 0){
                    r++;
                }
                else{
                    l--;
                }
            }
            else{
                l++;
            }
        }
       return l+r;
    }
};

 // for(char i : s){
        //     if(i == '('){
        //         st.push(i);
        //     }
        //     else{
        //         if(!st.empty() && i == ')'){
        //             st.pop();
        //         }
        //         else
        //         cnt++;
        //     }
        // }

        // while(!st.empty()){
        //     st.pop();
        //     cnt++;
        // }
        // return cnt;