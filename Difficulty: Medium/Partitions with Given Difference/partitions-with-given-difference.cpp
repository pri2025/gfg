//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& nums) {
        int sum = 0;
        for(auto num : nums) sum += num;
        if((sum + d) % 2) return 0;
        
        sum = (d + sum)/2;
        
        int mod = 1e9+7;
        vector<int> prev(sum + 1, 0), curr(sum + 1, 0);
        prev[0] = curr[0] = 1;
        
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=sum; j++) {
                if(nums[i-1] <= j)
                    curr[j] = prev[j-nums[i-1]] % mod + prev[j] % mod;
                else
                   curr[j] = prev[j] % mod;
            }
            prev = curr;
        }
        return prev[sum] % mod;
    }
};



// class Solution {
//   public:
//     int mod = 1e9 + 7;
//     int fn(int indx, int sum,vector<int>& arr,int n, vector<vector<int>> &memo){
        
//         if(indx >= n){
//             return (sum == 0);
           
//         }
        
//         if(memo[indx][sum] != -1) return memo[indx][sum];
        
//         int pick = 0, notpick = 0;
//         if(arr[indx] <= sum){
//             pick = fn(indx+1, sum-arr[indx],arr,n,memo) % mod;
//         }
//         notpick = fn(indx+1, sum,arr,n,memo) % mod;
        
//         return memo[indx][sum] = pick + notpick;
        
        
//     }
//     int countPartitions(int n, int d, vector<int>& arr) {
//         // Code here
//         int s=0;
//         for(int i : arr){
//             s += i;
//         }
//         if(s<d || (s+d) % 2!= 0) return 0;
//         int sum = (d+s)/2;// sum of subset1 should be this
        
//         vector<vector<int>> memo(n,vector<int>(sum+1,-1));
//         return fn(n-1,sum,arr,n,memo);
        
//     }
// };

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends