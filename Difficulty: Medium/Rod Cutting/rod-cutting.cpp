//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int fn(int indx, int n, int price[],vector<vector<int>> &memo){
        if(n==0 || indx <=0) return 0;
        if(memo[indx][n] != -1) return memo[indx][n];
        
        int pick = INT_MIN;
        if(indx <=n){
            pick = price[indx-1] + fn(indx,n-indx,price,memo);
        }
        int notpick = fn(indx-1,n,price,memo);
        
        return memo[indx][n] = max(pick,notpick);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> memo(n+1,vector<int>(n+1,-1));
        return fn(n,n,price,memo);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends