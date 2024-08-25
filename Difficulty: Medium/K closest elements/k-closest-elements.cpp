//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        int lb=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int ub=upper_bound(arr.begin(),arr.end(),x)-arr.begin();
        lb--;
        vector<int> ans;
        while(lb>=0 && ub<n)
        {
            if(abs(x-arr[lb])>=abs(arr[ub]-x))
            {
                ans.push_back(arr[ub]);
                ub++;
            }
            else
            {
                ans.push_back(arr[lb]);
                lb--;
            }
            if(ans.size()==k) return ans;
        }
        while(lb>=0)
        {
            ans.push_back(arr[lb]);
            lb--;
            if(ans.size()==k) return ans;
        }
        while(ub<n)
        {
            ans.push_back(arr[ub]);
            ub++;
            if(ans.size()==k) return ans;
        }
        
    }
    // vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
    //     // code here
    //     vector<int> res;
    //     priority_queue<pair<int,int>> pq;//maxheap
        
    //     for(int i=0; i<n;i++){
    //         if(arr[i] != x){
    //             pq.push({abs(arr[i]-x),arr[i]});
    //         }
    //         if(pq.size() > k){
    //             pq.pop();
    //         }
    //     }
    //     while(!pq.empty()){
    //         auto it = pq.top();
    //         res.push_back(it.second);
    //         pq.pop();
    //     }
        
    //     return res;
    // }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends