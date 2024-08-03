//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int k;
    int fn(int indx, vector<int> &arr,vector<int> &memo){
        if(indx== 0) return 0;
        
        if(memo[indx] != -1) return memo[indx];
        int mini= INT_MAX;
        for(int i =1;i<=k; i++){
            if(indx-i >=0){
                int jump = fn(indx-i,arr,memo) + abs(arr[indx] - arr[indx-i]);
                mini= min(mini,jump);
                memo[indx] = mini;
            }
        }
        
        return memo[indx];
    }
    int minimizeCost(vector<int>& arr, int& K) {
        // Code here
        int n= arr.size();
        k = K;
        vector<int> memo(n,-1);
        return fn(n-1,arr,memo);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends