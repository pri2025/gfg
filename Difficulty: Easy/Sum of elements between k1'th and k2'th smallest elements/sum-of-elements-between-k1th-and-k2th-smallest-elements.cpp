//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long fn(long long A[], long long k,long long n){
        priority_queue<long long> pq;
        
        for(long long i = 0; i<n; i++){
            pq.push(A[i]);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        long long s = fn(A,K1,N);
        long long l = fn(A,K2,N);
        long long sum = 0;
        for(long long i = 0; i<N; i++){
            if(A[i] > s && A[i] < l){
                sum += A[i];
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends