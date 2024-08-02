class Solution {
public:
    int fn(int i, int j,string &word1, string &word2,vector<vector<int>> &memo){
        if(i == -1) return j+1;
        if(j == -1) return i+1;

        if(memo[i][j] != -1) return memo[i][j];

        if(word1[i] == word2[j]) return 0 + fn(i-1,j-1,word1,word2,memo);

        else{
            //replace
            int r = 1 + fn(i-1, j-1,word1,word2,memo);
            
            //deletion
            int del = 1 + fn(i-1,j,word1,word2,memo);

            //insertion
            int add = 1 + fn(i,j-1,word1,word2,memo);

            memo[i][j] = min({r,del,add});
        }
        
        return memo[i][j];
    }
    int minDistance(string word1, string word2) {
        int n = word1.length(); int m = word2.length();
        if(n == 0)return m; 
        if(m ==0)return n;
        int i = n-1, j= m-1;
        vector<vector<int>> memo(n, vector<int>(m,-1));
        return fn(i,j,word1,word2,memo);
    }
};