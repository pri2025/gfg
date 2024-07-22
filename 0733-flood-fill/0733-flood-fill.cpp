class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& arr, int sr, int sc, int color) {
        int n = arr.size(); int m = arr[0].size();
        //vector<vector<int>> res(n, vector<int>(m,0));
        vector<vector<int>> vis(n, vector<int>(m,-1));

        queue<pair<int,int>> q;
        q.push({sr,sc});
        int org = arr[sr][sc];
        arr[sr][sc] = color; vis[sr][sc] = 1;
        //res[sr][sc] = color; vis[sr][sc] = 1;

        // for(int i = 0; i<n;i++){
        //     for(int j = 0; j<m; j++){
        //         if(arr[i][j] == 0){
        //             res
        //         }
        //     }
        // }

        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i<s;i++){
                auto c = q.front(); q.pop();
                int a = c.first; int b = c.second;
                for(auto it: dir){
                    int x = a+it.first;
                    int y = b+it.second;

                    if((x>=0 && x<n) && (y>=0 && y<m) && vis[x][y] == -1){
                        if(arr[x][y] == org){
                            arr[x][y] = color;
                            q.push({x,y});
                        }
                        vis[x][y] = 1;
                    }
                }
            }
        }
        return arr;
    }
};