//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    stack<char> st;
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        map<char, int> precedence;
        precedence['^'] = 5;
        precedence['*'] = 4;
        precedence['/'] = 4;
        precedence['+'] = 3;
        precedence['-'] = 3;
        string ans = "";
        
        for(auto it: s){
            if(isalpha(it) || (it>='0' && it<='9')){
                ans = ans + it;
            }
            else if(it == '('){
                st.push(it);
            }
            else if(it == ')'){
                while(!st.empty() && st.top() != '('){
                    ans = ans+st.top();
                    st.pop();
                }
                st.pop(); // '(' removed;
            }
            else{
                while(!st.empty() && precedence[st.top()] >= precedence[it]){
                    ans = ans+ st.top();
                    st.pop();
                }
                st.push(it);
            }
        }
        while(!st.empty()){
            ans = ans+ st.top();
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends