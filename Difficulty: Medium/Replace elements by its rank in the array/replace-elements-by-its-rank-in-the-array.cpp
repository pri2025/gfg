//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        vector<int> temp = arr;
        vector<int> res;
        sort(arr.begin(), arr.end());
        int rank = 1;
        map<int,int> mp;
        
        for(int i = 0; i<N;i++){
            if(mp[arr[i]] == 0){
                mp[arr[i]] = rank;
                rank++;
            }
        }
        
        for(int i =0; i<N; i++){
            res.push_back(mp[temp[i]]);
        }
        return res;
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
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends