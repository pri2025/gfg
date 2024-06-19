#include<bits/stdc++.h>
#include<stack>
class Solution {
public:
    stack<char> st;
    bool isValid(string s) {
        for( auto it: s){
            if(it == '(' || it == '[' || it == '{'){
                st.push(it);
            }
            else{
                if(st.size() == 0) return false;
                if(!st.empty()){
                    char c = st.top();
                    cout<<c;
                    st.pop();
                    if( (it == ')' && c == '(') || (it==']' && c=='[') 
                    || (it=='}' && c=='{')) 
                    continue; // after continue control shifted to for loop, to next iteration
                    else return false;
                } 
            }
        }
        return st.empty();
    }
};