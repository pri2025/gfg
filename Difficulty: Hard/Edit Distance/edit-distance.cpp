//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fn(int i, int j,string str1, string str2,vector<vector<int>> &memo){
        if(i == -1)return j+1;
        if(j==-1) return i+1;
        
        if(memo[i][j] != -1) return memo[i][j];
        
        if(str1[i] == str2[j]) return 0 + fn(i-1,j-1,str1,str2,memo);
        else{
            int r = 1 + fn(i-1,j-1,str1,str2,memo);
            int del = 1 + fn(i-1,j,str1,str2,memo);
            int add = 1 + fn(i,j-1,str1,str2,memo);
            
            memo[i][j] = min({r,del,add});
        }
        return memo[i][j];
    }
    int editDistance(string str1, string str2) {
        // Code here
        int n = str1.length(); int m = str2.length();
        vector<vector<int>> memo(n,vector<int>(m,-1));
        return fn(n-1,m-1,str1,str2,memo);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends