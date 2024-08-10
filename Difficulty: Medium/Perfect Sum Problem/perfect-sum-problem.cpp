//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        int mod = (int)1e9+7;
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        
        
        
        for(int i=0; i<n; i++) {
            dp[i][0] = 1;
        }
        
        if (arr[0] <= sum) {
            dp[0][arr[0]] = 1;
        }
        
        if(arr[0] == 0) dp[0][0] = 2;
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<=sum; j++) {
                int take = 0;
                if(arr[i] <= j) {
                    take = dp[i-1][j - arr[i]];
                }
                int notTake = dp[i-1][j]; 
                
                dp[i][j] = (take + notTake) % mod;
            }
        }
        
        
        return dp[n-1][sum];
    }
// 	int mod= 1e9+ 7;

// int fn(int ind, int arr[], int target, vector<vector<int>> &dp) {
//     // Base cases
//     if (target == 0)
//         return 1;

//     // Base case: If we have considered all elements and the target is still not 0, return 0
//     if (ind == 0)
//         return (arr[0] == target) ? 1 : 0;

//     // If the result for this state is already calculated, return it
//     if (dp[ind][target] != -1)
//         return dp[ind][target];

//     // Recursive cases
//     // 1. Exclude the current element
//     int notTaken = fn(ind - 1, arr, target, dp);

//     // 2. Include the current element if it doesn't exceed the target
//     int taken = 0;
//     if (arr[ind] <= target)
//         taken = fn(ind - 1,arr, target - arr[ind], dp);

//     // Store the result in the DP table and return
//     return dp[ind][target] = (notTaken + taken) % mod;
// }

// int perfectSum(int arr[], int n, int sum) {
//     // Initialize the memo table
//     vector<vector<int>> memo(n, vector<int>(sum + 1, -1));
    
//     return fn(n - 1, arr, sum, memo);
// }

// 	int fn(int indx,int arr[],int sum,vector<vector<int>> &memo){
// 	    if(sum == 0) return 1;
// 	    if(indx < 0) return 0;
	    
// 	    if(memo[indx][sum] != -1) return memo[indx][sum];
// 	    int pick= 0;
// 	    if(arr[indx] <=sum){
// 	        pick= fn(indx-1,arr,sum-arr[indx],memo);
// 	    }
// 	    int notpick = fn(indx-1,arr,sum,memo);
// 	    return memo[indx][sum] = pick+ notpick;
// 	}
// 	int perfectSum(int arr[], int n, int sum)
// 	{
//         // Your code goes here
//         vector<vector<int>> memo(n+1,vector<int>(sum+1,-1));
        
//         return fn(n-1,arr,sum,memo);
      
// 	}
	  
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