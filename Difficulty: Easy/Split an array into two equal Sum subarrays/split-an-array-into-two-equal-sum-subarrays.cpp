//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // bool fn(int indx,int t,vector<int>& arr,vector<vector<int>> &memo){
    //     if(t== 0) return true;
    //     if(indx== arr.size()-1) return (t == arr[arr.size()-1]);
        
    //     if(memo[indx][t] != -1) return memo[indx][t];
    //     bool pick = false;
    //     if(arr[indx]<= t){
    //         pick = fn(indx+1,t-arr[indx],arr,memo);
    //     }
    //     else{
    //         pick = false;
    //     }
    //     return memo[indx][t] = pick;
    // }
    bool canSplit(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum=0;
        for(int i = 0; i<n;i++){
            sum+=arr[i];
        }
        if(sum % 2 ==1) return false;
        int t = sum/2;
        int presum=0;
        for(int i=0; i<n;i++){
            presum+=arr[i];
            if(presum == t){
                return true;
            }
        }
        return false;
        // vector<vector<int>> memo(n,vector<int>(t+1,-1));
        // return fn(0,t,arr,memo);
        // vector<vector<bool>> dp(n+1,vector<bool>(t+1,false));
        // // for(int i= 0; i<=t;i++){
        // //     dp[0][i] = false;
        // // }
        // for(int i=0; i<=n;i++){
        //     dp[i][0] = true;
        // }
     

        
        // for(int i=1;i <=n; i++){
        //     for(int j=1;j <=t;j++){
        //         if(arr[i-1]<= j){
        //             dp[i][j] = dp[i-1][j-arr[i-1]];
        //         }
        //         else{
        //             dp[i][j] =false;
        //         }
        //     }
        // }
        //return dp[n][t];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends