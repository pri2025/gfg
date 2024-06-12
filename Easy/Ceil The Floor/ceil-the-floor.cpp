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


pair<int, int> getFloorAndCeil(int v[], int n, int x) {
    // code here
    
    int mini = -1;
    int maxi = -1;
    sort(v, v+n);
    int i = 0;
    int j = n-1;
    while( i<=j){
        int mid = (i+j)/2;
        if(v[mid] == x){
            return{v[mid], v[mid]};
        }
        else if(v[mid] < x){
            mini = v[mid];
            i = mid+1;
        }
        else{
            maxi = v[mid];
            j= mid -1;
        }
    }
    return{mini,maxi};
    
}

//for(int i=0; i<n; i++){
    //     if(arr[i] <= x && arr[i]>mini){
    //         mini = arr[i];
    //     }
    //     if(arr[i] >= x && arr[i]<maxi){
    //         maxi = arr[i];
    //     }
    // }
    // if(mini == INT_MIN){
    //     mini = -1;
    // }
    // if(maxi == INT_MAX){
    //     maxi = -1;
    // }
    // return {mini, maxi};