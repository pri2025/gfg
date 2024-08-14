//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        vector<vector<int>> dp(str1.size(), vector<int> (str2.size(), -1));
        int maxS = 0;
        for(int i=0; i<str1.size(); i++){
            for(int j=0; j<str2.size(); j++){
                if(str1[i] == str2[j] && dp[i][j] == -1){
                    int k=i, l=j;
                    while(k<str1.size() && l<str2.size() && str1[k] == str2[l]){
                        dp[k][l] = 1;
                        k++;
                        l++;
                    }
                    maxS = max(maxS, l-j);
                }
            }
        }
        return maxS;
    }
};
// class Solution {
//   public:
//     int fn(string &x, string &y, int n, int m){
//         if(n<0 || m<0) return 0;

//         if(x[n] == y[m]) return 1+fn(x,y,n-1,m-1);
//         else{
//             return max(fn(x,y,n-1,m), fn(x,y,n,m-1));
//         }
//         return 0;
//     }
//     int longestCommonSubstr(string str1, string str2) {
//         // your code here
//         int n = str1.length();
//         int m = str2.length();
//         if(n==0 || m ==0) return 0;
//         //vector<vector<int>> memo(n,vector<int>(m,0))
//         return fn(str1,str2,n-1,m-1); 
//     }
//};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends