class Solution {
public:


vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    vector<vector<int>> res(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;

    // Initialize the queue with all the cells containing 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                q.push({i, j});
                res[i][j] = 0;  // Distance to the nearest 0 for cells containing 0 is 0
            }
        }
    }

    // Directions for moving in the grid (up, down, left, right)
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Perform BFS
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int newX = x + dx;
            int newY = y + dy;

            if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                // If the new cell can be updated with a shorter distance
                if (res[newX][newY] > res[x][y] + 1) {
                    res[newX][newY] = res[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }
    }

    return res;
}

// int main() {
//     vector<vector<int>> mat = {
//         {0, 0, 0},
//         {0, 1, 0},
//         {1, 1, 1}
//     };

//     vector<vector<int>> result = updateMatrix(mat);

//     for (const auto& row : result) {
//         for (int val : row) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

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