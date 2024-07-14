//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void fn(int index,vector<int> &arr, vector<int> &ans,int sum){
        if(index == arr.size()){
            ans.push_back(sum);
            return;
        }
        
        fn(index+1,arr,ans,sum+arr[index]);
        fn(index+1,arr,ans,sum);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> ans;
        int sum = 0;
        //ans.push_back(0);
        if(n == 0){
            return ans;
        }
        int index = 0;
        fn(index,arr,ans,sum);
        return ans;
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
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends