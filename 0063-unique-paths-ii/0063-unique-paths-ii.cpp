class Solution {
public:
    int fn(int i ,int j, vector<vector<int>> &memo,vector<vector<int>>& arr){
        
        if(i ==0 && j==0) return 1;
        if(i<0||j<0) return 0;
       if(arr[i][j] == 1)return 0;
        if(memo[i][j]!= -1) return memo[i][j];
        int up = fn(i-1,j,memo,arr);
        int left = fn(i,j-1,memo,arr);

        return memo[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size(); int m = arr[0].size();
        if(arr[0][0] == 1) return 0;
       // if(n==1 && m==1 && arr[0][0] ==1) return 0;
        vector<vector<int>> memo(n,vector<int>(m,-1));
        return fn(n-1,m-1,memo,arr);
    }
};