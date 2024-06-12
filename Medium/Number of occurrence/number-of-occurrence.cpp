//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int left(int arr[], int n,int x){
	    int first = -1;
	    int i = 0;
	    int j = n-1;
	    while(i <= j){
	        int mid = (i+j)/2;
	        if(arr[mid] == x){
	            first = mid;
	            j = mid-1;
	        }
	        else if(arr[mid] < x){
	            i = mid+1;
	        }
	        else{
	            j = mid-1;
	        }
	    }
	    return first;
	}
	int right(int arr[], int n, int x){
	    int last = -1;
	    int i = 0;
	    int j = n-1;
	    while(i <= j){
	        int mid = (i+j)/2;
	        if(arr[mid] == x){
	            last = mid;
	            i = mid+1;
	        }
	        else if(arr[mid] < x){
	            i = mid+1;
	        }
	        else{
	            j = mid-1;
	        }
	    }
	    return last;
	}
	int count(int arr[], int n, int x) {
	    // code here
	    int l = left(arr,n, x);
	    if(l == -1){
	        return 0;
	    }
	    int r = right(arr,n, x);
	    return(r-l+1);
	   
	}
};

//{ Driver Code Starts.

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
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends