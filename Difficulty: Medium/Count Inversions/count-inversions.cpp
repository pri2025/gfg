//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[],int l, int m, int h){
        int i = l, j = m+1;
        long long num = 0;
        vector<long long> temp;
        while(i <=m && j <= h){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                num += m-i+1;
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i <= m){
            temp.push_back(arr[i]);
            i++;
        }
        while(j <=h){
            temp.push_back(arr[j]);
            j++;
        }
            
        for(int k = l; k<=h; k++){
            arr[k] = temp[k-l];
        }
        
        return num;
    }
    long long mergeSort(long long arr[], int l ,int h){
        if(l >= h) return 0 ;
        long long cnt = 0;
        int mid = (l+h)/2;
        cnt += mergeSort(arr,l,mid);
        cnt += mergeSort(arr,mid+1,h);
        cnt += merge(arr,l,mid,h);
        return cnt;
    }
    long long int inversionCount(long long arr[], int n) {
        // Your Code Here
        //cnt = 0;
        return mergeSort(arr,0,n-1);
        //return cnt;
        
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends