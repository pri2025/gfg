//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        int maxi = 0;
        int i= 0;
        int sum = 0;
        map<int, int> mpp;
        // Complete the function
        for(int i = 0; i<n ; i++){
            sum = sum + arr[i];
            if(sum == k){
                maxi = max(maxi, i+1);
            }
            int rem = sum-k;
            if(mpp.find(rem) != mpp.end()){
               maxi = max(maxi, i-mpp[rem]);
            }
            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
            
            
        }
        
       return maxi;
    }
    

};

//     int sum =0;
        //     for( int j=i; j<n ;j++){
        //         sum = sum+arr[j];
        //         if(sum == K){
        //             maxi = max(maxi , j-i+1);
        //         }
        //     }
        // }
        // return maxi;
        
        
         // while(j<n){
        //     while( i<= j && sum >K){
        //         sum = sum - arr[i];
        //         i++;
        //     }
        //     if(sum == K){
        //         maxi = max(maxi, j-i+1);
        //     }
            
        //     j++;
        //     if(j<n ){
        //         sum = sum+arr[j];
        //     }
        // }
        // return maxi;

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends