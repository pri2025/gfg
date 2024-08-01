//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int size;
    int fn(int index, int W, int wt[], int val[], vector<vector<int>>& dp) {
    if (index == size) {
        return 0;
    }
    
    if (dp[index][W] != -1) {
        return dp[index][W];
    }
    
    int take = INT_MIN;
    if (wt[index] <= W) {
        take = val[index] + fn(index + 1, W - wt[index], wt, val, dp);
    }
    int nottake = fn(index + 1, W,  wt, val, dp);
    dp[index][W] = std::max(take, nottake);
    
    return dp[index][W];
}

// Function to return the maximum value that can be put in knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n) { 
    size = n;
   vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return fn(0, W, wt, val, dp);
}
//   // int maxv;
//     int fn(int index, int W, int V,int wt[], int val[],vector<vector<int>> &dp){
//         // if(index == size){
//         //     maxv = max(maxv, V);
//         //     return;
//         // }
//         if(index == size) return V;
        
//         if(dp[index][W] != -1){
//             return dp[index][W];
//         }
//         int take = INT_MIN;
//         if(wt[index] <= W){
//              take = fn(index+1,W-wt[index],V+val[index],wt,val,dp);
//         }
//         int nottake = fn(index+1,W,V,wt,val,dp);
//         dp[index][W] = max(take,nottake);
        
//         return dp[index][W];
        
//         // if(wt[index] <= W){
//         //     dp[index][W] = fn(index+1,W-wt[index],V+val[index],wt,val);
//         // }
//         // fn(index+1,W,V,wt,val);
//     }
//     //Function to return max value that can be put in knapsack of capacity W.
//     int knapSack(int W, int wt[], int val[], int n) 
//     { 
//       // Your code here
//       size = n;// maxv = 0;
//       vector<vector<int>> dp(n,vector<int>(W+1,-1));
//       return fn(0,W,0,wt,val,dp);
//       //return maxv;
//     }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends