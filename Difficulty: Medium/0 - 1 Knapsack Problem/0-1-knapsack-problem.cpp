//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int fn(int indx,int W, int wt[], int val[], int n,vector<vector<int>>& memo){
        if(indx < 0|| W ==0){
            return 0 ;
        }
        if(memo[indx][W] !=-1) return memo[indx][W];
        int pick = INT_MIN;
        if(W >= wt[indx]){
            pick = val[indx] + fn(indx-1, W-wt[indx],wt,val,n,memo);
        }
        int notpick = fn(indx-1,W,wt,val,n,memo);
        memo[indx][W] = max(pick,notpick);
        return memo[indx][W];
        
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> memo(n,vector<int>(W+1,-1));
       return fn(n-1,W,wt,val,n,memo);
    }
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