//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  stack<string> st;
    string postToInfix(string s) {
        // Write your code here
        for(auto it: s){
            if(isalpha(it) || (it >= '0' && it<= '9')){
                st.push(string(1, it));
            }
            else{
                string A = st.top();
                st.pop();
                string B = st.top();
                st.pop();
                
                st.push('(' + B + it + A + ')');
                
            }
        }
        return st.top();
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends