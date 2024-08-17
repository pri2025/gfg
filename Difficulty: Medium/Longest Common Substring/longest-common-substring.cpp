//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        int n = str1.length();
        int m = str2.length();
        if(n==0 || m ==0) return 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i =0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i =0;i<=m;i++){
            dp[0][i]=0;
        }
        for(int i = 1; i<=n; ++i){
            for(int j = 1; j <=m; ++j){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        int maxi = 0;
        for(int i=0; i<=n;i++){
            for(int j=0;j<=m;j++){
                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends