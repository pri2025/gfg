class Solution {
public:
    int fn(string &x, string &y, int n, int m,vector<vector<int>> &memo){
        if(n<0 || m<0) return 0;
        if(memo[n][m] != -1) return memo[n][m];
        if(x[n] == y[m]) return memo[n][m] = 1+fn(x,y,n-1,m-1,memo);
        else{
            return memo[n][m] =  max(fn(x,y,n-1,m,memo), fn(x,y,n,m-1,memo));
        }
        return 0;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        if(n==0 || m ==0) return 0;
        vector<vector<int>> memo(n,vector<int>(m,-1));
        return fn(text1,text2,n-1,m-1,memo);
    }
};