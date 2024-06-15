//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int fn(int i,int n,int &ans){
	    if(n == 0){
	        return 1;
	    }
	   ans = ans*i;
	   fn(i,n-1,ans);
	   return ans;
	}
	int NthRoot(int n, int m)
	{
	    // Code here.
	    for(int i =1; i<=m; i++){
	        int ans = 1;
	        int x = fn(i,n,ans);
	        if(x == m){
	           return i;
	        }
	        if(x > m){
	            return -1;
	        }
	    }
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends