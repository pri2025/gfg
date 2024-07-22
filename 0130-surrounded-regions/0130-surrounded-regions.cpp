class Solution {
public:
    void dfs(int x,int y,vector<vector<int>> &vis,vector<vector<char>>& arr){
        if(x <0 || x >= vis.size() || y < 0 || y >= vis[x].size() || vis[x][y] == 1|| arr[x][y] != 'O'){
            return;
        }
        vis[x][y] = 1;

        dfs(x+0, y+1, vis,arr);
        dfs(x+0, y-1,vis,arr);
        dfs(x+1, y+0, vis,arr);
        dfs(x-1, y+0,vis,arr);
    }
    void solve(vector<vector<char>>& arr) {
        int n = arr.size(); int m = arr[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int i , j = 0;
        //marking of Os at boundary as they cannot be converted to X
        //apply dfs to mark Os connected with boundary Os.
        for(j = 0; j<m;j++){
            if(arr[0][j] == 'O'){
                dfs(0,j,vis,arr);
            }
            if(arr[n-1][j] == 'O'){
                dfs(n-1,j,vis,arr);
            }
        }

        for(i = 0; i<n;i++){
            if(arr[i][0] == 'O'){
                dfs(i,0,vis,arr);
            }
            if(arr[i][m-1] == 'O'){
                dfs(i,m-1,vis,arr);
            }
        }

        for(int i = 1; i <n-1;i++){
            for(int j = 1; j<m-1;j++){
                
                if(arr[i][j] == 'O'){
                    if(!vis[i][j]){
                        cout<<"1"<<" ";
                        arr[i][j] = 'X';
                    }     
                }
                
                
            }
        }
        
        
        
    }
};

// int cnt= 0;
//         for(int i = 0; i<n;i++){
//             for(int j = 0; j<m;j++){
//                 if(arr[i][j] == 'X'){
//                     cnt++;
//                 }
//             }
//         }
//         if(cnt != 0){
//             for(int i = 1; i<n-1;i++){
//             for(int j = 1; j<m-1;j++){
//                 if(arr[i][j] == 'O'){
//                    cout<<"1"<<" ";
//                     arr[i][j] = 'X';
//                 }
//             }
//         }
//         }