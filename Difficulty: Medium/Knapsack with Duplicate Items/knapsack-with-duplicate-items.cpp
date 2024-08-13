//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int fn(int indx, int w, int val[], int wt[],vector<vector<int>> &memo){
        if(indx<0 || w == 0) return 0;
        if(memo[indx][w] != -1) return memo[indx][w];
        int pick = INT_MIN;
        if(wt[indx] <=w ){
            pick = val[indx]+ fn(indx,w-wt[indx],val,wt,memo);
        }
        int notpick = fn(indx-1,w,val,wt,memo);
        return memo[indx][w] = max(pick,notpick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> memo(N,vector<int>(W+1,-1));
        return fn(N-1,W,val,wt,memo);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends