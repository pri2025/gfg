//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end()); 
        long long int t = 0;
        long long int ans= 0;
        for(int it=0; it < bt.size(); it++){
            int cnt = 0;
            if(it == bt.size()-1){
                break;
            }
            while(bt[it]){
                bt[it] -= 1;
                cnt++;
            }
            t += cnt;
            ans += t;
        }
        long long int n = bt.size();
        return floor(ans/n);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        long long ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends