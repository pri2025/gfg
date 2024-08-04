//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:


    // int fn(int i, int task,vector<vector<int>>& arr,vector<vector<int>> &memo,int n){
    //     if( i == n-1){
    //         int maxi =0;
    //         for(int k = 0; k<=2;k++){
    //             if(k != task){
    //                 maxi = max(maxi, arr[i][k]);
    //             }
    //         }
    //         return  maxi;
    //     }
    //     if(memo[i][task] != -1) return memo[i][task];
    //     int maxi = 0;
    //     for(int j = 0; j<=2; j++){
    //         if(j != task){
    //           int points = arr[i][j] + fn(i+1,j,arr,memo,n);
    //             maxi = max(maxi,points);
    //         }
           
    //     }
        
    //     return memo[i][task] = maxi;
    //     //return maxi;
    // }
     int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>>dp(n, vector<int>(4,-1));
        for(int i=0;i<3;i++){
            dp[0][i]=points[0][i];
        }
        
        for(int i=1;i<n;i++){
            
            dp[i][0]=max(dp[i-1][1], dp[i-1][2]) + points[i][0];
            
            dp[i][1]=max(dp[i-1][0], dp[i-1][2]) + points[i][1];
            
            dp[i][2]=max(dp[i-1][0], dp[i-1][1]) + points[i][2];
        }
        
        return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }

    // int maximumPoints(vector<vector<int>>& arr, int n) {
    //     // Code here
    //     int m = arr[0].size();
    //     //vector<vector<int>> memo(n,vector<int>(m+1,-1));
    //     //return fn(0,3,arr,memo,n); 
    //      // i tells current day nd j tells task performed on last day 
         
    //      vector<vector<int>> dp(n,vector<int>(m+1,-1));
    //      dp[0][0] = max(points[0][1], points[0][2]);
    //     dp[0][1] = max(points[0][0], points[0][2]);
    //     dp[0][2] = max(points[0][0], points[0][1]);
        
    //     for(int i =1 ; i<n;i++){
    //         for(int last = 0; last <4;last++){
    //             for(int task =0; task<=2;task++){
    //                 if(task != last){
    //                     int points = arr[i][task] + dp[i-1][last];
    //                 }
    //             }
    //         }
    //     }
    // }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends