//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fn(int indx,vector<int> &height,vector<int> &memo){
        if(indx == 0)return 0;
        if(memo[indx] !=-1) return memo[indx];
        
        int two = INT_MAX;
        int onestep = fn(indx-1,height,memo) + abs(height[indx] - height[indx-1]);
        
        if(indx>1){
            two = fn(indx-2,height,memo) + abs(height[indx] - height[indx-2]);
        }
        return memo[indx] =  min(onestep , two);
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int curr = INT_MAX;
        vector<int> memo(n,-1);
        return fn(n-1,height,memo);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends