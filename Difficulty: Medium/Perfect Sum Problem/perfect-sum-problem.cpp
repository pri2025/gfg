//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9 + 7;
	int N;
// 	int perfectSum(int arr[], int n, int sum)
//     {
//         // Your code goes here
//         int mod = (int)1e9+7;
//         vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        
        
        
//         for(int i=0; i<n; i++) {
//             dp[i][0] = 1;
//         }
        
//         if (arr[0] <= sum) {
//             dp[0][arr[0]] = 1;
//         }
        
//         if(arr[0] == 0) dp[0][0] = 2;
        
//         for(int i=1; i<n; i++) {
//             for(int j=0; j<=sum; j++) {
//                 int take = 0;
//                 if(arr[i] <= j) {
//                     take = dp[i-1][j - arr[i]];
//                 }
//                 int notTake = dp[i-1][j]; 
                
//                 dp[i][j] = (take + notTake) % mod;
//             }
//         }
        
        
//         return dp[n-1][sum];
//     }
 	int fn(int indx,int arr[],int sum,vector<vector<int>> &memo){
 	   
 	    if(indx >= N) return sum == 0;
	    
 	    if(memo[indx][sum] != -1) return memo[indx][sum];
 	    int ans= 0;
 	    if(arr[indx] <=sum){
 	        ans += fn(indx+1,arr,sum-arr[indx],memo);
            ans %= mod;
	    }
 	    ans += fn(indx+1,arr,sum,memo);
        ans %= mod;
 	    return memo[indx][sum] = ans;
 	}
 	int perfectSum(int arr[], int n, int sum)
	{
         // Your code goes here
         N = n;
        vector<vector<int>> memo(n+1,vector<int>(sum+1,-1));
        
        return fn(0,arr,sum,memo);
      
 	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends