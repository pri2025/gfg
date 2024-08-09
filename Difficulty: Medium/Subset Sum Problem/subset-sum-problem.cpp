//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool fn(int indx ,vector<int>arr,int sum,vector<vector<int>> &memo){
        if(sum == 0) return true;
        if(indx < 0) return false;
        if(memo[indx][sum] != -1) return memo[indx][sum];
        
        bool yes= false;
        if(arr[indx] <= sum){
             yes = fn(indx-1, arr,sum-arr[indx],memo);
        }
        bool no =  fn(indx-1,arr,sum,memo);
        return memo[indx][sum] = yes||no;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n = arr.size();
        vector<vector<int>> memo(n,vector<int>(sum+1, -1));
        if(fn(n-1,arr,sum,memo)) return true;
        return false;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends