//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    void dfs(vector<vector<int>> &mat,vector<vector<int>> &vis,int x, int y,
        vector<string> &res, string temp,int n){
        if(x < 0 || x >= n || y < 0 || y >= n || vis[x][y] == 1 || mat[x][y] == 0){
            return;
        }
        if(x == n-1 && y == n-1){
            res.push_back(temp);
            return;
        }
        vis[x][y] = 1;
        dfs(mat,vis,x+1,y,res,temp + 'D',n);//d
        dfs(mat,vis,x-1,y, res, temp + 'U',n);//u
        dfs(mat,vis,x,y+1, res, temp + 'R',n);//r
        dfs(mat,vis,x,y-1,res,temp + 'L',n);//l
        
        vis[x][y] = 0;
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n = mat.size(); 
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<string> res;
        
        if (mat[0][0] == 0 || mat[n-1][n-1] == 0) return res;
        
        dfs(mat,vis,0,0,res,"",n);
        return res;
        
        // queue<pair<int,int>> q;
        // if(mat[0][0] != 0) q.push(0,0); vis[0][0] = 1;
        
        // vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};//D U R L
        // vector<string> res;
        // while(!q.empty()){
        //     int cell = q.front(); q.pop();
        //     int x= cell.first; int y = cell.second;
        //     for(auto it: dir){
        //         int newx = x + it.first;
        //         int newy = y + it.second;
        //         if(newx>=0&& newx<n && newy>=0 && newy <n && vis[newx][newy] == 0){
        //             if(mat[newx][newy] == 1){
        //                 q.push({newx,newy});
        //                 vis[newx][newy] = 1;
        //                 if(it == {1,0}) res+="D";
        //                 else if(it == {-1,0}) res += "U";
        //                 else if(it == {0,1}) res+= "R";
        //                 else res+= "L";
        //             }
        //         }
        //     }
        // }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends