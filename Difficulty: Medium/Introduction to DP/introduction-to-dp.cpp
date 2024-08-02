//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int mod=1e9+7;
  long long int f(int n, vector<long long int> &dp){
      if(n<=1) return n;
      if(dp[n]!=-1) return dp[n];
      return (dp[n] = f(n-1,dp) + f(n-2,dp))%mod;
  }
  public:
    long long int topDown(int n) {
        // code here
        vector<long long int> dp(n+1,-1);
        return f(n,dp);
    }
    long long int bottomUp(int n) {
        // code here
       int pre2 = 0, pre = 1;
       for(int i=2;i<=n;i++){
           int curr = (pre + pre2)%mod;
           pre2 = pre;
           pre = curr;
       }
       return pre;
    }
    // int num ;
    // long long int mod = 10e9+7;
    // int fn(int index,vector<long long int> &memo){
    //     if(index <= 1){
    //         return index;
    //     }
    //     if(memo[index] != -1) return memo[index];
        
    //     return memo[index] = (fn(index-1,memo)+ fn(index-2, memo)) % mod;
    // } 
    // long long int topDown(int n) {
    //     // code here
    //     num = n;
    //     vector<long long int> memo(n+1,-1);
    //     return fn(n,memo);
        
    // }
    // long long int bottomUp(int n) {
    //     // code here
    //     if(n <= 1) return n;
    //     int prev = 1, prev2 = 0;
    //     for(int i=2;i<=n;i++){
    //         int curr = (prev + prev2) % mod;
    //         prev2 = prev; prev = curr;
    //     }
        
    //     return prev % mod;
        // vector<int> dp(n+1);
        // dp[0] = 0; dp[1] = 1;
        // for(int i=2; i<=n;i++){
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];
    //}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends