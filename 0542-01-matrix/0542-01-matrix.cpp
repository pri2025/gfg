class Solution {
public:


vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(),0));
    vector<vector<int>> vis(mat.size(),vector<int>(mat[0].size(),-1));
    queue<pair<pair<int,int>,int>> q; // coordinates and steps
    //enque all zeros
    for(int i = 0; i<mat.size(); i++){
        for(int j = 0; j<mat[i].size();j++){
            if(mat[i][j] == 0){
                res[i][j] = 0;
                vis[i][j] = 1;
                q.push({{i,j},0}); // index of zero
            }
        }
    }
    vector<pair<int,int>> directions ={{0,1},{0,-1},{1,0},{-1,0}};

    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i<n;i++){
            auto cell = q.front();
            int steps = cell.second; q.pop();
            for(auto dir : directions){
                int x = cell.first.first + dir.first;
                int y = cell.first.second + dir.second;

                if((x >=0 && x< mat.size()) &&(y>=0&& y<mat[x].size())&& vis[x][y] == -1){
                    vis[x][y] = 1;
                    res[x][y] = steps+1;
                    q.push({{x,y},steps+1});
                }
            }
        }
    }

    return res;

}
    // vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    //     int n = mat.size(); 
	//     int m = mat[0].size(); 
	//     // visited and distance matrix
	//     vector<vector<int>> vis(n, vector<int>(m, 0)); 
	//     vector<vector<int>> res(n, vector<int>(m, 0));
       
    //     queue<pair<pair<int,int>, int>> q;
        
    //     for(int i = 0; i<n; i++){
    //         for(int j = 0; j<m ; j++){
    //             if(mat[i][j] == 0){
    //                 q.push({i,j});
    //                 res[i][j] = 0;
    //                 vis[i][j] = 1;
    //             }
    //             else{
    //                 vis[i][j] = 0;
    //             }
    //         }
    //     }

    //     pair<int,int> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    //     while(!q.empty()){
    //         int cnt = 0;
    //         auto [x,y] = q.front(); q.pop();
    //         //int x = it.first; int y = it.second;
    //         if(mat[x][y] == 0){
    //             res[x][y] = 0;
    //         }
    //         else{
    //             for(auto i : directions){
    //                 int a = x+i.first;
    //                 int b = y+i.second;
    //                 if((a >= 0 && a<mat.size()) && (b >=0 && b <mat[x].size())
    //                  && mat[a][b] == 0){
    //                     res[x][y] = cnt;
    //                 }
    //                 while((a >= 0 && a<mat.size()) && (b >=0 && b <mat[x].size())
    //                  && mat[a][b] == 1){
    //                     cnt++;

    //                 }
    //             }
    //         }

    //     }
    // }
};