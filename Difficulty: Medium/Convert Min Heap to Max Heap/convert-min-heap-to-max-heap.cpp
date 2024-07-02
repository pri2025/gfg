//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }

    void heapify(vector<int> &arr, int n,int i){
        int maxi = i;
        
        int l= left(i);
        if(l <n && arr[l] > arr[i]) maxi = l;
        int r = right(i);
        if(r <n && arr[r] > arr[maxi]) maxi =r;
        if(maxi != i){
            swap(arr[maxi],arr[i]);
            heapify(arr,n,maxi); 
        }
    }

    void convertMinToMaxHeap(vector<int> &arr, int n){
        for(int i = (n-1)/2; i>=0; i--){
            heapify(arr,n,i);
        }
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends