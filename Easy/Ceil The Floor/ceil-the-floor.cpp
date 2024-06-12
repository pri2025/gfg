//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    
    int mini = INT_MIN;
    int maxi = INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i] <= x && arr[i]>mini){
            mini = arr[i];
        }
        if(arr[i] >= x && arr[i]<maxi){
            maxi = arr[i];
        }
    }
    if(mini == INT_MIN){
        mini = -1;
    }
    if(maxi == INT_MAX){
        maxi = -1;
    }
    // pair.push_back(mini);
    // pair.push_back(maxi);
    return {mini, maxi};
}