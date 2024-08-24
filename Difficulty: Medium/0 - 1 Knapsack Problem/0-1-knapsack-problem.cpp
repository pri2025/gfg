//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = val.size();
        // Your code here
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
         for(int i =0; i<=n;i++){
             dp[i][0] = 0;
         }
         
         for(int j= 0; j<=W;j++){
             dp[0][j] = 0;
         }
         
         for(int i =1; i<n+1;i++){
             for(int j = 1; j<W+1; j++){
                int pick = INT_MIN;
                if(wt[i-1] <= j){
                    pick = val[i-1] + dp[i-1][j-wt[i-1]];
                }
                int notpick = dp[i-1][j];
                
                dp[i][j] = max(pick,notpick);
             }
         }
         
         return dp[n][W];
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends