//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int i = 0;
	  //  int j = i+1;
	    int cnt= 1;
	    if(arr[i]<arr[n-1]){
	        return 0;
	    }
	    while(arr[i]<arr[i+1] && i<n-1){
	        cnt++;
	        i++;
	        
	    }
	    return cnt;
	   // while(i <= j){
	   //    int mid = (i+j)/2;
	   //    if(arr[i] <= arr[mid]){
	   //        // left sorted or sorted?
	   //        return cnt;
	   //    }
	   //    else{
	   //        //rotated
	   //        cnt++;
	   //        i++;
	   //    }
	       
	   // }
	   // return -1;
	}
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends