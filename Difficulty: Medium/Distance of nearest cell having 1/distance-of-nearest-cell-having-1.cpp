//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size(); int m = grid[0].size();
        
        vector<vector<int>> res(n,vector<int>(m,-1));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q; //coordinates, steps 
        for(int i = 0; i<n;i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j] == 1){
                    q.push({{i,j},0});
                    res[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }
        
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i<s; i++){
                auto c= q.front(); 
                int x = c.first.first; int y = c.first.second;
                int steps = c.second; q.pop();
                
                for(auto it: dir){
                    int a = x+it.first; int b = y+it.second;
                    
                    if((a>=0 && a<n) &&(b>=0 && b<m) && vis[a][b] == 0){
                        
                        res[a][b] = steps+1;
                        
                        vis[a][b] = 1;
                        q.push({{a,b},steps+1});
                    }
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends