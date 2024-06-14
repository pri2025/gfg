//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
  long long int ans = INT_MIN;
    long long int floorSqrt(long long int x) 
    {
        
     for(long long int i=1; i<=x; i++){
         if(i*i <= x){
             ans= max(ans, i);
         }
         else{
             break;
         }
     }   
     return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends