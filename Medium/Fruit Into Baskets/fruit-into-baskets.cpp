//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int n, vector<int> &arr) {
        int f1;
        
       int res = 0;
        for(int i =0; i<n-1 ; i++){
            f1 = arr[i];
            int f2 = -1;
            for(int j = i+1; j<n ; j++){
                if(arr[j] != f1){
                    f2 = arr[j];
                    break;
                }
            }
            if (f2 == -1) continue;
            int b1 =0, b2 = 0;
            for(int k = i; k<n ; k++){
                if(arr[k] == f1){
                    b1++;
                }
                else if(arr[k] == f2){
                    b2++;
                }
                else{
                    break;
                }
            }
            res = max(res, b1+b2);
        }
       //if(b2 == 0)return 1;
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends